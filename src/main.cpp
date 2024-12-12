#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "env.hpp"

using namespace geode::prelude;
namespace env = EnvironmentVariables;

// use on mod loaded so it shows a crashlog if anything here crashes
$on_mod(Loaded) {
	env::Manager::get()->setVariable("GD_VERSION", Loader::get()->getGameVersion());
	env::Manager::get()->setVariable("GEODE_VERSION", Loader::get()->getVersion().toNonVString());
}

class $modify(MenuLayer) {
	void onMoreGames(CCObject*) {
		env::string envstring = "HELLO %GEODE_VERSION%";

		log::info(R"(This is my awesome string thingy.
data: {}
size: {}
raw char: {}
		)", envstring.str(), envstring.size(), envstring.c_str());
	}
};