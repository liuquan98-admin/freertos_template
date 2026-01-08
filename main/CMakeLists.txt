idf_component_register(
    SRCS "freertos_template.c" "app_tasks.c"  # main的源文件
    INCLUDE_DIRS "."     # main的头文件目录（若有）
    REQUIRES driver freertos led
    )