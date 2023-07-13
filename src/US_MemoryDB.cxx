#include <algorithm>
#include "US_MemoryDB.hxx"


namespace US {

	void MemoryDB::Insert(std::string_view tag, std::string_view url){
		m_Database.emplace(tag, url);
	}

	std::optional<std::string> MemoryDB::Lookup(std::string_view tag){
		const auto it = m_Database.find(tag);
		if (it != m_Database.end()) {
			return std::make_optional(it->second);
		}

		return std::nullopt;
	}

};