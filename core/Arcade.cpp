//
// EPITECH PROJECT, 2018
// arcade
// File description:
// .cpp arcade
//

#include <dirent.h>
#include <sys/types.h>
#include "Arcade.hpp"

Arcade::Arcade(char *libarg)
	:_gameName("menu"), _menu(std::unique_ptr<Menu>(new Menu))
{
	std::string slibarg = libarg;
	size_t posSlash = slibarg.find_last_of('/');

	if (posSlash == slibarg.npos)
		posSlash = 0;
	else
		++posSlash;
	
	if (!slibarg.compare(0, 15, "lib/lib_arcade_") &&
	    !slibarg.compare(slibarg.size() - 3, 3, ".so")) {
		_libName = slibarg.substr(posSlash + 11, slibarg.size() - posSlash - 14);
		std::cout << "Arcade Initialized" << std::endl;
	} else {
		throw std::exception();
	}
}

Arcade::~Arcade()
{
}

void	Arcade::openGameLib(const std::string &libpath, const std::string &libname)
{
	create_game_t *createObj;
	void *handle_tmp;

	handle_tmp = dlopen(libpath.c_str(), RTLD_LAZY);
	if (!handle_tmp) {
		std::cerr << "Cannot load " << libpath.c_str() << std::endl;
		throw std::exception();
	}
	dlerror();
	createObj = (create_game_t*) dlsym(handle_tmp, "create");
	if (dlerror()) {
		std::cerr << "Cannot load symbol create"<< std::endl;
		throw std::exception();
	}
	_handleGame.push_back(handle_tmp);
	_gGame[libname] = createObj();
	_gGame[libname]->init();
	
}

void	Arcade::openGraphLib(const std::string &libpath, const std::string &libname)
{
	create_graph_t *createObj;
	void *handle_tmp;

	handle_tmp = dlopen(libpath.c_str(), RTLD_LAZY);
	if (!handle_tmp) {
		std::cerr << "Cannot load " << libpath.c_str() << std::endl;
		throw std::exception();
	}
	dlerror();
	createObj = (create_graph_t*) dlsym(handle_tmp, "create");
	if (dlerror()) {
		std::cerr << "Cannot load symbol create"<< std::endl;
		throw std::exception();
	}
	_handleGraph.push_back(handle_tmp);
	_glib[libname] = createObj();
}

void	Arcade::loadDirLibs(const std::string &path, const lib_t ltype)
{
	DIR *rep = opendir(path.c_str());
	struct dirent *filebuffer;
	std::string filename, libpath, libname;

	if (!rep) {
		std::cerr << "Directory " << path << " not found." << std::endl;
		throw std::exception();
	}
	while ((filebuffer = readdir(rep)) != nullptr) {
		filename = filebuffer->d_name;
		if (!filename.compare(0, 11, "lib_arcade_") &&
		    !filename.compare(filename.size() - 3, 3, ".so")) {
			libpath = path;
			libpath += '/';
			libpath += filename;
			libname = filename.substr(11, filename.size() - 14);
			if (ltype == LGRAPHICALS)
				openGraphLib(libpath, libname);
			else if (ltype == LGAMES)
				openGameLib(libpath, libname);
		}
	}
	if (closedir(rep) == -1) {
		std::cerr << "Fail closing directory " << path << std::endl;
		throw std::exception();
	}
}

void	Arcade::getNewLib()
{
	std::map<std::string, IGraphical *>::iterator	libIt;

	for (libIt = _glib.begin(); libIt != _glib.end(); ++libIt) {
		if (libIt->first == _libName) {
			libIt++;
			if (libIt != _glib.end()) {
				_glib[_libName]->destroy();
			} else {
				_glib[_libName]->destroy();
				libIt = _glib.begin();
			}
			_libName = libIt->first;
			_glib[_libName]->init();
		}
	}
}

void	Arcade::closeme()
{
	for (unsigned int i = 0; i < _handleGame.size(); i++) {
		dlclose(_handleGame[i]);
	}
	for (unsigned int i = 0; i < _handleGraph.size(); i++) {
		if (i == 1)
			continue;
		dlclose(_handleGraph[i]);
	}
}

void	Arcade::checkAction()
{
	int	action;

	if (_gameName == "menu")
		action = _menu->getAction();
	else
		action = _gGame[_gameName]->getAction();
	switch (action) {
	case EXITPGRM:
		_glib[_libName]->destroy();
		closeme();
		exit(0);
	case NIBBLER:
		_gameName = "nibbler";
		_gGame[_gameName]->setUsername(_menu->getUsername());
		break;
	case PACMAN:
		_gameName = "pacman";
		_gGame[_gameName]->setUsername(_menu->getUsername());
		break;
	case CHANGELIB:
		getNewLib();
                break;
	case ENDGAME:
		_gameName = "menu";
		break;
	};
}

bool	Arcade::isSpecialKey(int key)
{
	switch (key) {
        case PREVLIB:
		getNewLib();
                return (true);
        case NEXTLIB:
		getNewLib();
                return (true);
        case PREVGAME:
		if (_gameName == "nibbler")
			_gameName = "pacman";
		else
			_gameName = "nibbler";
		return (true);
        case NEXTGAME:
		if (_gameName == "nibbler")
			_gameName = "pacman";
		else
			_gameName = "nibbler";
		return (true);
        case BACKTOMENU:
		_gameName = "menu";
                return (true);
	case EXIT:
		_glib[_libName]->destroy();
		closeme();
		exit(0);
        };
	return (false);
}

void	Arcade::start()
{
	int	key;

	if (_glib.find(_libName) == _glib.end())
		return ;
	_glib[_libName]->init();
	_menu->init();
	while(1) {
		key = _glib[_libName]->getKeyPress();
		if (isSpecialKey(key) == true)
			continue ;
		if (_gameName == "menu") {
			_menu->applyKeyPress(key);
			_glib[_libName]->display(_menu->getMap(), _menu->getSelect());
		} else {
			_gGame[_gameName]->applyKeyPress(key);
			_glib[_libName]->display(_gGame[_gameName]->getMap(), _gGame[_gameName]->getSelect());
			std::this_thread::sleep_for (std::chrono::milliseconds(1));
		}
		checkAction();
	}
}

