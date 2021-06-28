#include <iostream>
#include <conio.h>
#include "kaitaistream.h"
#include "quicktime_mov.h"
#include <fstream>

std::ifstream is("E:\keep_right.MOV", std::ifstream::binary);

kaitai::kstream ks(&is);

quicktime_mov_t data(&ks);

int main()
{

	std::cout << "data() = " << data.atoms()->items()->data()->get()->atom_type() << " size = " << data.atoms()->items()->size() << std::endl;
	data.atoms()->items()->data()->get()->body()->_io()->seek(0);
	std::cout << "pos " << data.atoms()->items()->data()->get()->body()->_io()->pos() << std::endl;
	std::cout << data.atoms()->items()->data()->get()->_io()->read_bytes_full() << std::endl << std::endl;

	std::cout << "back() = " << data.atoms()->items()->back().get()->atom_type() << " size = " << data.atoms()->items()->back().get()->_io()->size() << std::endl;
	data.atoms()->items()->back()->body()->_io()->seek(0);
	std::cout << data.atoms()->items()->back().get()->body()->_io()->read_bytes_full() << std::endl << std::endl;

	std::cout << "_root() = " << data.atoms()->_root()->atoms()->items()->data()->get()->atom_type() << " size = " << data.atoms()->_root()->atoms()->items()->data()->get()->body()->_io()->size() << std::endl;
	data.atoms()->items()->data()->get()->body()->_io()->seek(0);
	std::cout << data.atoms()->_root()->atoms()->items()->data()->get()->body()->_io()->read_bytes_full() << std::endl;
	//std::cout << data.atoms()->_io()->read_bytes_full(); // full file

	_getch();
	return 0;

}
