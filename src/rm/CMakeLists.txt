add_library(redbaserm STATIC 
    rm_error.cc 
    rm_bitmap.cc)


add_executable(test_rm_bitmap rm_bitmap_test.cc)
target_link_libraries(test_rm_bitmap redbaserm)