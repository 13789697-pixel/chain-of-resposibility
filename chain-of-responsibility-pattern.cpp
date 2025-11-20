#include <iostream>
using namespace std;

class Handler {
protected:
	Handler* next;//вказівник на наступного бробника ланцюжка//
public:
	Handler(): next(nullptr) {}
	void setNext(Handler* h) { next = h; } //для побудови ланцюжка//
	virtual void handle(const string& request) { //handle - обробляє або передає далі//
		if (next) next -> handle(request);
		else {
			cout << "No handle could process:" << request << endl;
		}
	}
	virtual ~Handler() = default;
};
class EmailHandler : public Handler {
public:
	void handle(const std::string& request) override {
		if (request == "email") {
			std::cout << "EmailHandler: Processing email request." << std::endl;
		}
		else {
			Handler::handle(request);
		}
	}
};
class SmsHandler : public Handler {
public:
	void handle(const string& request) override {
		if (request == "sms") {
			cout << "SmsHandler: Processing sms request." << endl;
		}
		else {
			Handler::handle(request);
		}
	}
};
int main() {
	EmailHandler email;
	SmsHandler sms;

	email.setNext(&sms);

	email.handle("email");
	email.handle("sms");

	return (0);
}