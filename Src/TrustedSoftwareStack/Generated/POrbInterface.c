
  #include "POrbInterface.h"
  #define P_SEQ
  #define P_BOOL_EXPR(x0, f0) P_SEQ(p_tmp_expr_0 = (x0), p_tmp_bool = PrtPrimGetBool(p_tmp_expr_0), ((f0) ? PrtFreeValue(p_tmp_expr_0) : 0U), p_tmp_bool)
  static PRT_TYPE P_GEND_TYPE_0 = 
  {
    PRT_KIND_ANY,
    
    {
        NULL
    }
  };
  static PRT_TYPE P_GEND_TYPE_1 = 
  {
    PRT_KIND_BOOL,
    
    {
        NULL
    }
  };
  static PRT_TYPE P_GEND_TYPE_2 = 
  {
    PRT_KIND_EVENT,
    
    {
        NULL
    }
  };
  static PRT_TYPE P_GEND_TYPE_3 = 
  {
    PRT_KIND_INT,
    
    {
        NULL
    }
  };
  static PRT_TYPE P_GEND_TYPE_4 = 
  {
    PRT_KIND_MACHINE,
    
    {
        NULL
    }
  };
  static PRT_TYPE P_GEND_TYPE_5 = 
  {
    PRT_KIND_NULL,
    
    {
        NULL
    }
  };
  static PRT_TYPE P_GEND_TYPE_6 = 
  {
    PRT_KIND_MACHINE,
    NULL
  };
  static PRT_STRING P_GEND_TYPE_NMDTUP_NARR_7[] = 
  {
    "topic",
    "sub"
  };
  static PRT_TYPE *P_GEND_TYPE_NMDTUP_TARR_7[] = 
  {
    &P_GEND_TYPE_Topics,
    &P_GEND_TYPE_4
  };
  static PRT_NMDTUPTYPE P_GEND_TYPE_NMDTUP_7 = 
  {
    2,
    P_GEND_TYPE_NMDTUP_NARR_7,
    P_GEND_TYPE_NMDTUP_TARR_7
  };
  static PRT_TYPE P_GEND_TYPE_7 = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_7
    }
  };
  static PRT_STRING P_GEND_TYPE_NMDTUP_NARR_8[] = 
  {
    "topic",
    "ev",
    "payload"
  };
  static PRT_TYPE *P_GEND_TYPE_NMDTUP_TARR_8[] = 
  {
    &P_GEND_TYPE_Topics,
    &P_GEND_TYPE_2,
    &P_GEND_TYPE_0
  };
  static PRT_NMDTUPTYPE P_GEND_TYPE_NMDTUP_8 = 
  {
    3,
    P_GEND_TYPE_NMDTUP_NARR_8,
    P_GEND_TYPE_NMDTUP_TARR_8
  };
  static PRT_TYPE P_GEND_TYPE_8 = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_8
    }
  };
  static PRT_VALUE P_GEND_VALUE_0 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_altitude_reached_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_1 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_attitude_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_2 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_battery_critical_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_3 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_battery_status_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_4 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_command_ack_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_5 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_extended_sys_state_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_6 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_geofence_reached_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_7 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_global_position_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_8 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_gps_health_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_9 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_gps_raw_int_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_10 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_gps_status_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_11 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_heartbeat_status_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_12 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_heartbeat_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_13 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_local_position_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_14 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_px4status_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_15 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_vehicle_armed_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_16 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_vehicle_crashed_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_17 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_vehicle_disarmed_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_18 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_vehicle_landed_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_19 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_vehicle_loitering_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_20 = 
  {
    PRT_VALUE_KIND_INT,
    
    {
        Topics_vehicle_ready_topic
    }
  };
  static PRT_VALUE P_GEND_VALUE_21 = 
  {
    PRT_VALUE_KIND_EVENT,
    
    {
        PRT_SPECIAL_EVENT_HALT
    }
  };
  static PRT_VALUE P_GEND_VALUE_22 = 
  {
    PRT_VALUE_KIND_NULL,
    
    {
        PRT_SPECIAL_EVENT_NULL
    }
  };
  PRT_EVENTDECL P_EVENT_POrbPublish_STRUCT = 
  {
    P_EVENT_POrbPublish,
    "POrbPublish",
    4294967295U,
    &P_GEND_TYPE_8,
    0U,
    NULL
  };
  PRT_EVENTDECL P_EVENT_POrbSubscribe_STRUCT = 
  {
    P_EVENT_POrbSubscribe,
    "POrbSubscribe",
    4294967295U,
    &P_GEND_TYPE_7,
    0U,
    NULL
  };
  PRT_TYPE P_GEND_TYPE_POrbInterface = 
  {
    PRT_KIND_MACHINE,
    NULL
  };
  PRT_TYPE P_GEND_TYPE_POrbPubMsgType = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_8
    }
  };
  PRT_TYPE P_GEND_TYPE_POrbSubMsgType = 
  {
    PRT_KIND_NMDTUP,
    
    {
        (PRT_MAPTYPE *)&P_GEND_TYPE_NMDTUP_7
    }
  };
  