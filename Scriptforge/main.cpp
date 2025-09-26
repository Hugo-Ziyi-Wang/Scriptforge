import Scriptforge.err;
import std;
using namespace std;
int main() {
	try
	{
		throw Scriptforge::Err::Error{};
	}
	catch (const Scriptforge::Err::Error& e)
	{
		cout << e;
	}
}