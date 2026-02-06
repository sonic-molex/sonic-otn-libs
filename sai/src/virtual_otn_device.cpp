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


/* WSS Device - spectrum power entry management */
sai_status_t virtual_otn_wss_device::add_spec_power(sai_object_id_t spec_power_id, sai_object_id_t parent_wss_id)
{
    if (spec_power_entries.find(spec_power_id) != spec_power_entries.end()) {
        logger::warn(std::string(__func__) + ": Spec power already exists: " + std::to_string(spec_power_id));
        return SAI_STATUS_ITEM_ALREADY_EXISTS;
    }
    spec_power_entries[spec_power_id] =
        std::make_unique<virtual_otn_wss_spec_power_entry>(parent_wss_id, spec_power_id);
    logger::debug(std::string(__func__) + ": Added WSS spec power " + std::to_string(spec_power_id) +
                  " to WSS " + std::to_string(parent_wss_id));
    return SAI_STATUS_SUCCESS;
}

sai_status_t virtual_otn_wss_device::remove_spec_power(sai_object_id_t spec_power_id)
{
    auto it = spec_power_entries.find(spec_power_id);
    if (it == spec_power_entries.end()) {
        logger::warn(std::string(__func__) + ": Spec power not found: " + std::to_string(spec_power_id));
        return SAI_STATUS_ITEM_NOT_FOUND;
    }
    spec_power_entries.erase(it);
    logger::debug(std::string(__func__) + ": Removed WSS spec power " + std::to_string(spec_power_id));
    return SAI_STATUS_SUCCESS;
}

virtual_otn_wss_spec_power_entry* virtual_otn_wss_device::get_spec_power(sai_object_id_t spec_power_id)
{
    auto it = spec_power_entries.find(spec_power_id);
    return (it != spec_power_entries.end()) ? it->second.get() : nullptr;
}

sai_status_t virtual_otn_wss_device::remove_all_spec_power()
{
    logger::debug(std::string(__func__) + ": removing all spec power entries (" +
                 std::to_string(spec_power_entries.size()) + ")");
    spec_power_entries.clear();
    return SAI_STATUS_SUCCESS;
}

