#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Person{
	public:
		string name;
		shared_ptr<Person> mother;
		shared_ptr<Person> father;
		vector<weak_ptr<Person>> kids;
	//	vector<shared_ptr<Person>> kids;
		Person(const string& n,
		shared_ptr<Person> m=nullptr,
		shared_ptr<Person> f=nullptr):
		name(n),mother(m),father(f){
		    	cout<<"created: "<<name<<endl;
		}
		~Person(){
			cout<<"delete "<<name<<endl;
		}
};

shared_ptr<Person> createFamily(const string& name){
	shared_ptr<Person> mom(new Person(name+"'s mom"));
	shared_ptr<Person> dad(new Person(name+"'s dad"));
	shared_ptr<Person> kid(new Person(name,mom,dad));
	//weak_ptr<Person> kid1(new Person(name,mom,dad));
	//weak_ptr<Person> wkid(kid);
	mom->kids.push_back(kid);
	dad->kids.push_back(kid);
	return kid;
}

int main(){
	shared_ptr<Person> p = createFamily("Ivan");
	cout<<" - name of the 1st kid: "<<p->mother->kids[0].lock()->name<<endl;
//	cout<<" - name of the 1st kid: "<<p->mother->kids[0]->name<<endl;
//	p=createFamily("Anna");
//	cout<<" - name of the 1st kid: "<<p->mother->kids[0]->name<<endl;
	shared_ptr<Person> *p1 = &p;
	
}
