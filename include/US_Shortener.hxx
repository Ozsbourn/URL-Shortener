#include <functional>
#include <optional>
#include <string>

#include "US_Database.hxx"


#ifndef US_SHORTENER_HXX_
#define US_SHORTENER_HXX_

namespace US {

	class Shortener {
	public:
		explicit Shortener(Database& db, std::function<std::string()>&& hasher);

		std::string               ToShort(std::string_view url);
		std::optional<std::string> Lookup(std::string_view tag); 
	private:
		Database& m_DB;

		std::function<std::string()> m_RandomStr;
	};

};

#endif // US_SHORTENER_HXX_