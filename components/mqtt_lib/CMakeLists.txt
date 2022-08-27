set(EXTRA_COMPONENT_DIRS $ENV{IDF_PATH})
idf_component_register(SRCS "mqtt_lib.c"
                    INCLUDE_DIRS "include")
