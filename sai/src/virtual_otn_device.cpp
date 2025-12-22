#include "virtual_otn_device.h"
#include <cstdlib>
#include "logger.h"

/* OCM Device */
// Channel management
   sai_status_t virtual_otn_ocm_device::add_channel(sai_object_id_t parent_ocm_id, sai_object_id_t channel_id)
    {
        if (channels.find(channel_id) != channels.end()) {
            logger::warn(std::string(__func__) + ": Channel already exists: " + std::to_string(channel_id));
            return SAI_STATUS_ITEM_ALREADY_EXISTS;
        }

        // map of channel ids to ocm channel objects
        channels[channel_id] = std::make_unique<virtual_otn_ocm_channel>(parent_ocm_id, channel_id);

        logger::debug(std::string(__func__) + ": Added OCM channel "
                      + std::to_string(channel_id) + " to OCM " + std::to_string(parent_ocm_id));

        return SAI_STATUS_SUCCESS;
    }

sai_status_t virtual_otn_ocm_device::remove_channel(sai_object_id_t channel_id)
{
    auto it = channels.find(channel_id);
    if (it == channels.end()) {
        logger::warn(std::string(__func__) + " channel not found: " + std::to_string(channel_id));
        return SAI_STATUS_ITEM_NOT_FOUND;
    }
    
    channels.erase(it);
    logger::debug(std::string(__func__) + " removed channel " + std::to_string(channel_id));
    
    return SAI_STATUS_SUCCESS;
}

sai_status_t virtual_otn_ocm_device::remove_all_channels()
{
    logger::warn(std::string(__func__) + ": removing all channels (" + std::to_string(channels.size()) + ")");
    channels.clear();
    logger::warn(std::string(__func__) + ": removed all channels");

    return SAI_STATUS_SUCCESS;
}

virtual_otn_ocm_channel* virtual_otn_ocm_device::get_channel(sai_object_id_t channel_id)
{
    logger::debug(std::string(__func__) + " channel_id " + std::to_string(channel_id));
    auto it = channels.find(channel_id);
    return (it != channels.end()) ? it->second.get() : nullptr;
}


