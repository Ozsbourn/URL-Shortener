#include "US_CrowServer.hxx"
#include "US_Shortener.hxx"


namespace US {

	const auto index = R"(
		<!DOCTYPE html>
		<html>
			<body>

				<h2>URL shortener</h2>

				<form action="/">
				  URL:<br>
				  <input type="text" name="url" value="https://">
				  <input type="submit" value="Short URL">
				</form> 

			</body>
		</html>
	)";

	CrowServer::CrowServer(void){
		CROW_ROUTE(m_App, "/")
		.name("frontpage")
		.methods("GET"_method)
		([this] (const crow::request& request) {
			return HandleHomePage(request);
		});

		CROW_ROUTE(m_App, "/<string>")
		.name("redirect")
		.methods("GET"_method)
		([this] (std::string_view tag) {
			return HandleRedirect(std::move(tag));
		});
	}

	void CrowServer::Run(void) {
	    m_App.port(8080)
	        // .multithreaded()
	        .run();
	}

	crow::response CrowServer::HandleHomePage(const crow::request& request) {
		auto url = request.url_params.get("url");
	    if (url != nullptr) {
	        try {
	            constexpr auto root = "localhost:8080/";
	            auto short_url = m_Shortener.ToShort(url);

	            return crow::response(200, "<a href=\"/" + short_url + "\">" + root + short_url + "</a>");
	        } catch (const std::runtime_error&) {
	            return crow::response(400);
	        }

	        return crow::response(500);
	    }


	    return crow::response(200, front_page);
	}

	crow::response CrowServer::HandleRedirect(std::string_view tag) {
	    if (const auto url = m_Shortener.Lookup(tag); url) {
	        crow::response response(302);
	        response.set_header("Location", *url);

	        return response;
	    }

	    return crow::response(404);
	}

};