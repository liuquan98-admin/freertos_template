idf_component_register(
    SRCS  "app_tasks.c" "freertos_template.c"  # main的源文件
    INCLUDE_DIRS  "."    # main的头文件目录（若有）
    REQUIRES driver freertos led ledc
    )