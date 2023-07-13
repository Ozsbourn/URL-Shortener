#include <map>
#include "US_Database.hxx"

#ifndef US_MEMORYDB_HXX_
#define US_MEMORYDB_HXX_

namespace US {

	class MemoryDB : public Database {
	private:
		std::map<std::string, std::string_view, std::less<>> m_Database;
	public:
		explicit MemoryDB(void) = default;

		void Insert(std::string_view tag, std::string_view url) override;

		std::optional<std::string> Lookup(std::string_view tag) const override;

		~MemoryDB(void) = default;
	};

};

#endif // US_MEMORYDB_HXX_