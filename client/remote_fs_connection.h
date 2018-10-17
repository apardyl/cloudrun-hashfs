#ifndef CLOUDRUN_HASHFS_FILEREQUESTER_H
#define CLOUDRUN_HASHFS_FILEREQUESTER_H

#include "common/proto/remotefs.grpc.pb.h"
#include "common/lock_map.h"
#include <unordered_map>
#include <mutex>
#include <condition_variable>

class RemoteFSConnection {
    std::unique_ptr<remotefs::RemoteFS::Stub> stub;

    int status_to_errno(const grpc::Status &status);

    LockMap<std::string> lock_map;

    bool create_base_dir(const std::string &filename);

public:
    explicit RemoteFSConnection(const std::string &server_address);

    int fetch_file(const std::string &filename, const std::string &save_as);

    int get_checksum(const std::string &filename, std::string *checksum);

    int get_stat(const std::string &filename, struct stat *st);

    int get_stat(const std::string &filename, filesystem::Stat *st);

    int get_dir(const std::string &path, filesystem::Node *node);
};


#endif //CLOUDRUN_HASHFS_FILEREQUESTER_H
