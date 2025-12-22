#include "sai_meta_data.h"
#include "logger.h"

sai_uint64_t otn_ocm_channel_obj::min_frequency = 0x7FFFFFFFFFFFFFFF;

void
sai_id_map_t::free_id(sai_object_id_t sai_object_id)
{
    const auto& it = id_map.find(sai_object_id);
    if (it == id_map.end()) {
        logger::info("sai_id " + std::to_string(sai_object_id) + "not found, skip.");
        return;
    }

    if (it->second == nullptr) return;

    logger::info("freeing object with sai_id " + std::to_string(sai_object_id));
    delete static_cast<sai_obj *>(it->second);

    id_map.erase(sai_object_id);
    unused_id.push_back(sai_object_id);
}

void
sai_id_map_t::free_all()
{
    logger::info("id_map size " + std::to_string(id_map.size()));
    for (auto &id : id_map) {
        logger::info("freeing object with sai_id " + std::to_string(id.first));
        if (id.second != nullptr) {
            delete static_cast<sai_obj *>(id.second);
        }
    }

    id_map.clear();
    unused_id.clear();
}
