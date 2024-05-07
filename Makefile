all: read_settings

libMLX90640_API.a:
	$(MAKE) -C mlx90640-library libMLX90640_API.a

read_settings: libMLX90640_API.a
	$(CXX) $(CXXFLAGS) read_settings.cpp mlx90640-library/libMLX90640_API.a utils.cpp -I mlx90640-library/headers -o read_settings

take_gray_pic: libMLX90640_API.a
	$(CXX) $(CXXFLAGS) take_gray_pic.cpp mlx90640-library/libMLX90640_API.a utils.cpp -I mlx90640-library/headers -o take_gray_pic

take_relative_pic: libMLX90640_API.a
	$(CXX) $(CXXFLAGS) take_relative_pic.cpp mlx90640-library/libMLX90640_API.a utils.cpp -I mlx90640-library/headers -o take_relative_pic

take_absolute_pic: libMLX90640_API.a
	$(CXX) $(CXXFLAGS) take_absolute_pic.cpp mlx90640-library/libMLX90640_API.a utils.cpp -I mlx90640-library/headers -o take_absolute_pic

dump_ee: libMLX90640_API.a
	$(CXX) $(CXXFLAGS) dump_ee.cpp mlx90640-library/libMLX90640_API.a utils.cpp -I mlx90640-library/headers -o dump_ee

rsync: read_settings take_gray_pic take_relative_pic take_absolute_pic
	rsync read_settings root@192.168.77.1:ir-cam/
	rsync take_gray_pic root@192.168.77.1:ir-cam/
	rsync take_relative_pic root@192.168.77.1:ir-cam/
	rsync take_absolute_pic root@192.168.77.1:ir-cam/
