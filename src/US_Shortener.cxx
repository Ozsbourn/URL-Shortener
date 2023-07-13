#include "US_Shortener.hxx"
#include "US_Database.hxx"

#ifndef US_SHORTENER_HXX_
#define US_SHORTENER_HXX_

namespace US {
	
	Shortener::Shortener(Database& db, std::function<std::string()>&& hasher)
	: m_DB(db),
	  m_RandomStr(hasher) {}

	std::string Shortener::ToShort(std::string_view url) {
		auto tag = m_RandomStr;
		m_DB.insert(tag, url);

		return tag;
	}

	std::optional<std::string> Shortener::Lookup(std::string_view tag) {
		return m_DB.Lookup(tag);
	}

};

#endif // US_SHORTENER_HXX_ 