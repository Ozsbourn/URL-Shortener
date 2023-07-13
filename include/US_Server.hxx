#ifndef US_SERVER_HXX_
#define US_SERVER_HXX_

namespace US {

	class Server {
	public:
		explicit Server(void) = default;

		virtual void Setup(void) = 0;
		virtual void   Run(void) = 0;

		virtual ~Server(void) = default;
	};

};

#endif // US_SERVER_HXX_