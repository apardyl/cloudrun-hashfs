#ifndef HASHFS_DATASTORE_H
#define HASHFS_DATASTORE_H

#include <string>
#include "remote_fs_connection.h"

class HashStore {
private:
    std::string shared_cache_path;

    RemoteFSConnection * downloader;

    std::string hash_to_path(const std::string &hash);

    std::unordered_set<std::string> hash_missmaches;

    std::mutex hash_missmaches_mutex;
public:
    HashStore(std::string shared_cache_path, RemoteFSConnection *downloader);

    int open_hash(const std::string &hash, const std::string &real_path, int flags);
};


#endif //HASHFS_DATASTORE_H
