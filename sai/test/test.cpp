#include "sai_adapter.h"
#include "logger.h"
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


void kvm_flow_test()
{
    sai_api_version_t ver = 0;
    sai_status_t rc = sai_query_api_version(&ver);
    cout << "sai_query_api_version, rc = " << rc << ", version = " << ver << endl;

    rc = sai_api_initialize(0, NULL);
    cout << "sai_api_initialize, rc = " << rc << endl;

    // switch
    sai_switch_api_t *switch_api = NULL;
    rc = sai_api_query(SAI_API_SWITCH, (void **)&switch_api);
    cout << "sai_api_query, rc = " << rc << ", switch_api = " << switch_api << endl;

    vector<sai_attribute_t> attr_list;
    sai_attribute_t attr;
    attr.id = SAI_SWITCH_ATTR_INIT_SWITCH;
    attr.value.booldata = true;
    attr_list.push_back(attr);

    // create switch
    sai_object_id_t switch_id = -1;
    rc = switch_api->create_switch(&switch_id, attr_list.size(), attr_list.data());
    cout << "create_switch, rc = " << rc << ", switch_id = " << switch_id << endl;

    // attenuator
    sai_otn_attenuator_api_t *attenuator_api = NULL;
    rc = sai_api_query((sai_api_t)SAI_API_OTN_ATTENUATOR, (void **)&attenuator_api);
    cout << "sai_api_query, rc = " << rc << ", attenuator_api = " << attenuator_api << endl;

    std::string voa_name = "VOA0-0";
    std::cout << "------------------------------------------------------" << std::endl << "creating " << voa_name << std::endl;

    sai_object_id_t attenuator_id = -1;
    attr_list.clear();
    attr.id = SAI_OTN_ATTENUATOR_ATTR_NAME;
    memcpy(attr.value.chardata, voa_name.c_str(), voa_name.size() + 1);
    attr_list.push_back(attr);
    attr.id = SAI_OTN_ATTENUATOR_ATTR_ATTENUATION;
    attr.value.u32 = 850;
    attr_list.push_back(attr);
    rc = attenuator_api->create_otn_attenuator(&attenuator_id, switch_id, attr_list.size(), attr_list.data());
    cout << "create_otn_attenuator " << voa_name << ", rc = " << rc << ", attenuator_id = " << attenuator_id << endl;

    attr_list.clear();
    attr.id = SAI_OTN_ATTENUATOR_ATTR_ATTENUATION;
    attr.value.u32 = 0;
    attr_list.push_back(attr);
    attr.id = SAI_OTN_ATTENUATOR_ATTR_ACTUAL_ATTENUATION;
    attr.value.u32 = 0;
    attr_list.push_back(attr);
    rc = attenuator_api->get_otn_attenuator_attribute(attenuator_id, attr_list.size(), attr_list.data());
    cout << "get_otn_attenuator_attribute, rc = " << rc << std::endl
         << "SAI_OTN_ATTENUATOR_ATTR_FIX_ATTENUATION = " << attr_list[0].value.u32 << endl
         << "SAI_OTN_ATTENUATOR_ATTR_ACTUAL_ATTENUATION = " << attr_list[1].value.u32 << endl;

    // oa
    sai_otn_oa_api_t *oa_api = NULL;
    rc = sai_api_query((sai_api_t)SAI_API_OTN_OA, (void **)&oa_api);
    cout << "sai_api_query, rc = " << rc << ", oa_api = " << oa_api << endl;

    //OA0
    std::string oa_name = "OA0-0";
    std::cout << "------------------------------------------------------" << std::endl << "creating " << oa_name << std::endl;

    sai_object_id_t oa_id = -1;
    attr_list.clear();
    attr.id = SAI_OTN_OA_ATTR_NAME;
    memcpy(attr.value.chardata, oa_name.c_str(), oa_name.size() + 1);
    attr_list.push_back(attr);
    attr.id = SAI_OTN_OA_ATTR_TARGET_GAIN;
    attr.value.u32 = 420;
    attr_list.push_back(attr);
    attr.id = SAI_OTN_OA_ATTR_TARGET_GAIN_TILT;
    attr.value.s32 = 40;
    attr_list.push_back(attr);
    rc = oa_api->create_otn_oa(&oa_id, switch_id, attr_list.size(), attr_list.data());
    cout << "create_otn_oa " << oa_name << ", rc = " << rc << ", oa_id = " << oa_id << endl;

    attr_list.clear();
    attr.id = SAI_OTN_OA_ATTR_ACTUAL_GAIN;
    attr.value.s32 = 0;
    attr_list.push_back(attr);
    rc = oa_api->get_otn_oa_attribute(oa_id, attr_list.size(), attr_list.data());
    cout << "get_otn_oa_attribute, rc = " << rc << ", SAI_OTN_OA_ATTR_ACTUAL_GAIN = " << attr_list[0].value.s32 << endl;


    //OA1
    oa_id = -1;
    oa_name = "OA0-1";
    std::cout << "------------------------------------------------------" << std::endl << "creating " << oa_name << std::endl;

    attr_list.clear();
    attr.id = SAI_OTN_OA_ATTR_NAME;
    memcpy(attr.value.chardata, oa_name.c_str(), oa_name.size() + 1);
    attr_list.push_back(attr);
    attr.id = SAI_OTN_OA_ATTR_TARGET_GAIN;
    attr.value.u32 = 520;
    attr_list.push_back(attr);
    attr.id = SAI_OTN_OA_ATTR_TARGET_GAIN_TILT;
    attr.value.s32 = -50;
    attr_list.push_back(attr);
    rc = oa_api->create_otn_oa(&oa_id, switch_id, attr_list.size(), attr_list.data());
    cout << "create_otn_oa " << oa_name << ", rc = " << rc << ", oa_id = " << oa_id << endl;

    attr_list.clear();
    attr.id = SAI_OTN_OA_ATTR_ACTUAL_GAIN;
    attr.value.s32 = 0;
    attr_list.push_back(attr);
    rc = oa_api->get_otn_oa_attribute(oa_id, attr_list.size(), attr_list.data());
    cout << "get_otn_oa_attribute, rc = " << rc << ", SAI_OTN_OA_ATTR_ACTUAL_GAIN = " << attr_list[0].value.s32 << endl;


    // ocm
    sai_otn_ocm_api_t *ocm_api = NULL;
    rc = sai_api_query((sai_api_t)SAI_API_OTN_OCM, (void **)&ocm_api);
    cout << "sai_api_query, rc = " << rc << ", ocm_api = " << ocm_api << endl;

    std::string ocm_name = "OCM0-1";
    std::cout << "------------------------------------------------------" << std::endl << "creating " << ocm_name << std::endl;

    sai_object_id_t ocm_id = -1;
    attr_list.clear();
    attr.id = SAI_OTN_OCM_ATTR_NAME;
    memcpy(attr.value.chardata, ocm_name.c_str(), ocm_name.size() + 1);
    attr_list.push_back(attr);
    rc = ocm_api->create_otn_ocm(&ocm_id, switch_id, attr_list.size(), attr_list.data());
    cout << "create_otn_ocm " << ocm_name << ", rc = " << rc << ", ocm_id = " << ocm_id << endl;

    // ocm channel
    uint64_t cur_freq = 191262500;
    uint64_t band_width = 75000;
    int ocm_channel_count = 65;
    std::vector<sai_object_id_t> ocm_channels;
    for (int i = 1; i <= ocm_channel_count; i++) {
        sai_object_id_t ocm_channel_id = -1;
        attr_list.clear();
        uint64_t end_freq = cur_freq + band_width;
        std::string channel_name = ocm_name + "|" + std::to_string(cur_freq);
        std::cout << "------------------------------------------------------" << std::endl << "creating " << channel_name << std::endl;
        attr.id = SAI_OTN_OCM_CHANNEL_ATTR_NAME;
        memcpy(attr.value.chardata, channel_name.c_str(), channel_name.size() + 1);
        attr_list.push_back(attr);
        attr.id = SAI_OTN_OCM_CHANNEL_ATTR_LOWER_FREQUENCY;
        attr.value.u64 = cur_freq;
        attr_list.push_back(attr);
        attr.id = SAI_OTN_OCM_CHANNEL_ATTR_UPPER_FREQUENCY;
        attr.value.u64 = end_freq;
        attr_list.push_back(attr);
        rc = ocm_api->create_otn_ocm_channel(&ocm_channel_id, switch_id, attr_list.size(), attr_list.data());
        cout << "create_otn_ocm_channel " << channel_name << ", rc = " << rc << ", ocm_channel_id = " << ocm_channel_id << endl;
        ocm_channels.push_back(ocm_channel_id);

        // next frequency
        cur_freq = end_freq;
    }

    for (auto ch : ocm_channels) {
        sai_attribute_t attr = {SAI_OTN_OCM_CHANNEL_ATTR_POWER, {0}};
        rc = ocm_api->get_otn_ocm_channel_attribute(ch, 1, &attr);
        cout << "get_otn_ocm_channel_attribute, rc = " << rc << ", value = " << attr.value.s32 << endl;
    }

    // --- Create OSC 0 device ---
    string osc_name = "OSC0-0";
    cout << "------------------------------------------------------" << endl;
    cout << "Creating " << osc_name << endl;

    attr_list.clear();

    // SAI_OTN_OSC_ATTR_NAME
    attr.id = SAI_OTN_OSC_ATTR_NAME;
    memset(attr.value.chardata, 0, sizeof(attr.value.chardata));
    memcpy(attr.value.chardata, osc_name.c_str(), osc_name.size() + 1);
    attr_list.push_back(attr);

    sai_otn_osc_api_t *osc_api = NULL;
    rc = sai_api_query((sai_api_t)SAI_API_OTN_OSC, (void **)&osc_api);
    cout << "sai_api_query, rc = " << rc << ", osc_api = " << osc_api << endl;
    sai_object_id_t osc_id = -1;

    // Create OSC object via SAI
    rc = osc_api->create_otn_osc(&osc_id, switch_id, attr_list.size(), attr_list.data());
    cout << "create_otn_osc " << osc_name << ", rc = " << rc << ", osc_id = " << osc_id << endl;

    // --- Create OSC 1 device ---
    osc_name = "OSC1-0";
    cout << "------------------------------------------------------" << endl;
    cout << "Creating " << osc_name << endl;

    attr_list.clear();

    // SAI_OTN_OSC_ATTR_NAME
    attr.id = SAI_OTN_OSC_ATTR_NAME;
    memset(attr.value.chardata, 0, sizeof(attr.value.chardata));
    memcpy(attr.value.chardata, osc_name.c_str(), osc_name.size() + 1);
    attr_list.push_back(attr);

    rc = sai_api_query((sai_api_t)SAI_API_OTN_OSC, (void **)&osc_api);
    cout << "sai_api_query, rc = " << rc << ", osc_api = " << osc_api << endl;

    // Create OSC object via SAI
    rc = osc_api->create_otn_osc(&osc_id, switch_id, attr_list.size(), attr_list.data());
    cout << "create_otn_osc " << osc_name << ", rc = " << rc << ", osc_id = " << osc_id << endl;

    // --- WSS (Wavelength Selective Switch) ---
    sai_otn_wss_api_t *wss_api = NULL;
    rc = sai_api_query((sai_api_t)SAI_API_OTN_WSS, (void **)&wss_api);
    cout << "sai_api_query, rc = " << rc << ", wss_api = " << wss_api << endl;

    std::string wss_name = "WSS0-0";
    cout << "------------------------------------------------------" << endl;
    cout << "Creating WSS media channel " << wss_name << endl;

    sai_object_id_t wss_id = -1;
    attr_list.clear();
    attr.id = SAI_OTN_WSS_ATTR_INDEX;
    attr.value.u32 = 0;
    attr_list.push_back(attr);
    attr.id = SAI_OTN_WSS_ATTR_LOWER_FREQUENCY;
    attr.value.u64 = 191300000;  // MHz
    attr_list.push_back(attr);
    attr.id = SAI_OTN_WSS_ATTR_UPPER_FREQUENCY;
    attr.value.u64 = 196100000;  // MHz
    attr_list.push_back(attr);
    attr.id = SAI_OTN_WSS_ATTR_ADMIN_STATE;
    attr.value.s32 = SAI_OTN_WSS_ADMIN_STATE_ENABLED;
    attr_list.push_back(attr);
    attr.id = SAI_OTN_WSS_ATTR_SOURCE_PORT_NAME;
    memset(attr.value.chardata, 0, sizeof(attr.value.chardata));
    memcpy(attr.value.chardata, "WSS0-IN", 8);
    attr_list.push_back(attr);
    attr.id = SAI_OTN_WSS_ATTR_DEST_PORT_NAME;
    memset(attr.value.chardata, 0, sizeof(attr.value.chardata));
    memcpy(attr.value.chardata, "WSS0-OUT", 9);
    attr_list.push_back(attr);

    rc = wss_api->create_otn_wss(&wss_id, switch_id, attr_list.size(), attr_list.data());
    cout << "create_otn_wss, rc = " << rc << ", wss_id = " << wss_id << endl;

    attr_list.clear();
    attr.id = SAI_OTN_WSS_ATTR_INDEX;
    attr.value.u32 = 0;
    attr_list.push_back(attr);
    attr.id = SAI_OTN_WSS_ATTR_LOWER_FREQUENCY;
    attr.value.u64 = 0;
    attr_list.push_back(attr);
    attr.id = SAI_OTN_WSS_ATTR_OPER_STATUS;
    attr.value.s32 = 0;
    attr_list.push_back(attr);
    rc = wss_api->get_otn_wss_attribute(wss_id, attr_list.size(), attr_list.data());
    cout << "get_otn_wss_attribute, rc = " << rc << endl
         << "  INDEX = " << attr_list[0].value.u32 << endl
         << "  LOWER_FREQUENCY = " << attr_list[1].value.u64 << endl
         << "  OPER_STATUS = " << attr_list[2].value.s32 << endl;

    // --- WSS spectrum power entries ---
    cout << "------------------------------------------------------" << endl;
    cout << "Creating WSS spectrum power entries" << endl;

    std::vector<sai_object_id_t> wss_spec_power_ids;
    uint64_t spec_lower = 191300000;
    uint64_t spec_upper = 191375000;
    int spec_power_count = 4;
    const char* wss_src_port = "LineIn0";
    for (int i = 0; i < spec_power_count; i++) {
        sai_object_id_t spec_power_id = -1;
        attr_list.clear();
        memset(attr.value.chardata, 0, sizeof(attr.value.chardata));
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_SOURCE_PORT_NAME;
        memcpy(attr.value.chardata, wss_src_port, strlen(wss_src_port) + 1);
        attr_list.push_back(attr);
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_LOWER_FREQUENCY;
        attr.value.u64 = spec_lower;
        attr_list.push_back(attr);
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_UPPER_FREQUENCY;
        attr.value.u64 = spec_upper;
        attr_list.push_back(attr);
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_TARGET_POWER;
        attr.value.s32 = -300;  // 0.01 dBm -> -3.00 dBm
        attr_list.push_back(attr);
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_ATTENUATION;
        attr.value.s32 = 500;   // 0.01 dB -> 5.00 dB
        attr_list.push_back(attr);

        rc = wss_api->create_otn_wss_spec_power(&spec_power_id, switch_id, attr_list.size(), attr_list.data());
        cout << "create_otn_wss_spec_power [" << spec_lower << "," << spec_upper << "], rc = " << rc
             << ", spec_power_id = " << spec_power_id << endl;
        wss_spec_power_ids.push_back(spec_power_id);
        spec_lower = spec_upper;
        spec_upper += 75000;
    }
    
    wss_spec_power_ids.clear();

    // Create a second WSS (WSS0-1) for LineIn1
    std::string wss_name2 = "WSS0-1";
    cout << "------------------------------------------------------" << endl;
    cout << "Creating WSS media channel " << wss_name2 << endl;

    sai_object_id_t wss_id2 = -1;
    attr_list.clear();
    attr.id = SAI_OTN_WSS_ATTR_INDEX;
    attr.value.u32 = 1;
    attr_list.push_back(attr);
    attr.id = SAI_OTN_WSS_ATTR_LOWER_FREQUENCY;
    attr.value.u64 = 191300000;  // MHz
    attr_list.push_back(attr);
    attr.id = SAI_OTN_WSS_ATTR_UPPER_FREQUENCY;
    attr.value.u64 = 196100000;  // MHz
    attr_list.push_back(attr);
    attr.id = SAI_OTN_WSS_ATTR_ADMIN_STATE;
    attr.value.s32 = SAI_OTN_WSS_ADMIN_STATE_ENABLED;
    attr_list.push_back(attr);
    attr.id = SAI_OTN_WSS_ATTR_SOURCE_PORT_NAME;
    memset(attr.value.chardata, 0, sizeof(attr.value.chardata));
    memcpy(attr.value.chardata, "LineIn1", 7);
    attr_list.push_back(attr);
    attr.id = SAI_OTN_WSS_ATTR_DEST_PORT_NAME;
    memset(attr.value.chardata, 0, sizeof(attr.value.chardata));
    memcpy(attr.value.chardata, "LineOut1", 8);
    attr_list.push_back(attr);

    rc = wss_api->create_otn_wss(&wss_id2, switch_id, attr_list.size(), attr_list.data());
    cout << "create_otn_wss, rc = " << rc << ", wss_id = " << wss_id2 << endl;

    uint64_t spec_lower2 = 191337500;
    uint64_t spec_upper2 = 191412500;
    int spec_power_count2 = 2;
    const char* wss_src_port2 = "LineIn1";
    for (int i = 0; i < spec_power_count2; i++) {
        sai_object_id_t spec_power_id = -1;
        attr_list.clear();
        memset(attr.value.chardata, 0, sizeof(attr.value.chardata));
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_SOURCE_PORT_NAME;
        memcpy(attr.value.chardata, wss_src_port2, strlen(wss_src_port2) + 1);
        attr_list.push_back(attr);
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_LOWER_FREQUENCY;
        attr.value.u64 = spec_lower2;
        attr_list.push_back(attr);
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_UPPER_FREQUENCY;
        attr.value.u64 = spec_upper2;
        attr_list.push_back(attr);
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_TARGET_POWER;
        attr.value.s32 = -250;  // 0.01 dBm -> -2.50 dBm
        attr_list.push_back(attr);
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_ATTENUATION;
        attr.value.s32 = 300;   // 0.01 dB -> 3.00 dB
        attr_list.push_back(attr);

        rc = wss_api->create_otn_wss_spec_power(&spec_power_id, switch_id, attr_list.size(), attr_list.data());
        cout << "create_otn_wss_spec_power [" << spec_lower2 << "," << spec_upper2 << "], rc = " << rc
             << ", spec_power_id = " << spec_power_id << endl;
        wss_spec_power_ids.push_back(spec_power_id);
        spec_lower2 = spec_upper2;
        spec_upper2 += 75000;
    }

    for (size_t i = 0; i < wss_spec_power_ids.size(); i++) {
        attr_list.clear();
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_LOWER_FREQUENCY;
        attr.value.u64 = 0;
        attr_list.push_back(attr);
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_ATTENUATION;
        attr.value.s32 = 0;
        attr_list.push_back(attr);
        attr.id = SAI_OTN_WSS_SPEC_POWER_ATTR_ACTUAL_ATTENUATION;
        attr.value.s32 = 0;
        attr_list.push_back(attr);
        rc = wss_api->get_otn_wss_spec_power_attribute(wss_spec_power_ids[i], attr_list.size(), attr_list.data());
        cout << "get_otn_wss_spec_power_attribute spec_power_id=" << wss_spec_power_ids[i] << ", rc = " << rc
             << ", LOWER_FREQ = " << attr_list[0].value.u64
             << ", ATTENUATION = " << attr_list[1].value.s32
             << ", ACTUAL_ATTENUATION = " << attr_list[2].value.s32 << endl;
    }

    // Remove WSS spec power entries then WSS
    for (auto id : wss_spec_power_ids) {
        rc = wss_api->remove_otn_wss_spec_power(id);
        cout << "remove_otn_wss_spec_power " << id << ", rc = " << rc << endl;
    }
    rc = wss_api->remove_otn_wss(wss_id);
    cout << "remove_otn_wss " << wss_id << ", rc = " << rc << endl;

    rc = wss_api->remove_otn_wss(wss_id2);
    cout << "remove_otn_wss " << wss_id2 << ", rc = " << rc << endl;

    sai_api_uninitialize();
}

int main()
{
    kvm_flow_test();

    return 0;
}
