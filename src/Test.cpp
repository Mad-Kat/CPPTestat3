#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "IndexableSet.h"

#include <iostream>

#include <functional>

void test_rotate_1_2_3() {
	
	IndexableSet<int> asdf{1,2,3,4,5,6};
	//IndexableSet<int, std::greater<int>> asdf{1,2,3,4,5,6};
	

	std::cout << asdf.front();
	std::cout << asdf.back();
	
	for(int i: asdf){
		std::cout << i;
	}

	ASSERT_EQUAL(asdf[-4],asdf[2]);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(test_rotate_1_2_3));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
