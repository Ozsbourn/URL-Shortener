#include ".\..\..\..\Libs\Crow\include\crow.h"

#ifndef US_CROWSERVER_HXX_
#define US_CROWSERVER_HXX_

namespace US {

	class CrowServer {
	private:
		Shortener&      m_Shortener;
		crow::SimpleApp m_App;

		crow::response HandleHomePage(const crow::request& request);
		crow::response HandleRedirect(std::string_view tag);
	public:
		explicit CrowServer(Shortener& shortener) = default;

		void Setup(void) override;		
		void   Run(void) override;
	};

};

#endif // US_CROWSERVER_HXX_