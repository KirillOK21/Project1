#include <iostream>
#include <conio.h>
#include "kaitaistream.h"
#include "quicktime_mov.h"
#include <fstream>

//std::ifstream is("E:\clip03.mov", std::ifstream::binary);
std::ifstream is("E:\keep_right.MOV", std::ifstream::binary);

kaitai::kstream ks(&is);

quicktime_mov_t data(&ks);



int main()
{
	//data.atoms()->items()->shrink_to_fit();

	//data.atoms()->items()->pop_back(); //назад
	//data.atoms()->items()->push_back(0); // вперед

	//std::cout << "begin() = " << data.atoms()->items()->begin()->get()->atom_type() << std::endl;
	std::cout << ' ' << std::endl;
	

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
	//std::cout << data.atoms()->_io()->read_bytes_full(); // весь файл

	
	

	
	/*data.atoms()->items()->data()->get()->body()->_io()->seek(0);
	std::cout << "read_s1 " << data.atoms()->items()->data()->get()->body()->_io()->read_s1() << std::endl;
	data.atoms()->items()->data()->get()->body()->_io()->seek(0);
	std::cout << "read_s2be " << data.atoms()->items()->data()->get()->body()->_io()->read_s2be() << std::endl;
	data.atoms()->items()->data()->get()->body()->_io()->seek(0);
	std::cout << "read_s4be " << data.atoms()->items()->data()->get()->body()->_io()->read_s4be() << std::endl;
	data.atoms()->items()->data()->get()->body()->_io()->seek(0);
	std::cout << "read_s8be " << data.atoms()->items()->data()->get()->body()->_io()->read_s8be() << std::endl;
	data.atoms()->items()->data()->get()->body()->_io()->seek(0);
	std::cout << "read_s2le " << data.atoms()->items()->data()->get()->body()->_io()->read_s2le() << std::endl;
	data.atoms()->items()->data()->get()->body()->_io()->seek(0);
	std::cout << "read_s4le " << data.atoms()->items()->data()->get()->body()->_io()->read_s4le() << std::endl;
	data.atoms()->items()->data()->get()->body()->_io()->seek(0);
	std::cout << "read_s4le " << data.atoms()->items()->data()->get()->body()->_io()->read_s8le() << std::endl;
	data.atoms()->items()->data()->get()->body()->_io()->seek(0);
	std::cout << "read_s4le " << data.atoms()->items()->data()->get()->body()->_io()->read_u1() << std::endl;
	data.atoms()->items()->data()->get()->body()->_io()->seek(0);*/

	_getch();
	return 0;

}
