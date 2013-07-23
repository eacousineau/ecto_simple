#include <ecto/ecto.hpp>
#include <iostream>

namespace ecto_test
{

using ecto::tendrils;
using namespace std;

struct Test
{
	static void declare_io(const tendrils &params, tendrils &in, tendrils &out)
	{
		in.declare(&Test::name_, "name", "Name of stuff", "bob");
		in.declare(&Test::vector_, "vector", "Values in list").required(true);
		out.declare(&Test::count_, "count", "Number of stuff");
	}
	
	int process(const tendrils& /*in*/, const tendrils& /*out*/)
	{
		cout << "Name: " << *name_ << endl;
		for (auto &value : *vector_)
			cout << value << " ";
		cout << endl;
		*count_ = name_->size() + vector_->size();
	}
	
	// Input
	ecto::spore<string> name_;
	ecto::spore<vector<int> > vector_;
	// Output
	ecto::spore<int> count_;
};

}

ECTO_DEFINE_MODULE(ecto_test)
{ }

ECTO_CELL(ecto_test, ecto_test::Test, "Test", "Prints 'Hello' to standard output.")
