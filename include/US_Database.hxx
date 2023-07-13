#include <optional>
#include <string>
#include <string_view>

#ifndef US_DATABASE_HXX_
#define US_DATABASE_HXX_

namespace US {

	class Database {
	public:
		explicit Database(void) = default;
		
		virtual void Insert(std::string_view tag, std::string_view url) = 0;

		virtual std::optional<std::string> Lookup(std::string_view tag) = 0;

		virtual ~Database(void) = default;
	};

};

#endif // US_DATABASE_HXX_