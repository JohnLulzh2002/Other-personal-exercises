#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const string g[]={ "男","女"};
void login();
set<string> ids;
void save();
void load();
class person{
protected:
	string id;  //学号/工号
	string pass;//密码
	void changePass(string _pass){
		pass=_pass;
		save();
	}
public:
	bool loginCheck(string _id,string _pass){
		if(id==_id&&pass==_pass){
			work();
			return true;
		}
		return false;
	}
	void resetPass(string _pass){
		pass=_pass;
	}
	virtual void work()=0;
};
class student :public person{
private:
	string name,gender;
	int chi,math,eng,sum;
	void updateSum(){
		sum=chi+math+eng;
	}
public:
	student(string _id="",string _pass="8888",string _name="",string _gender=g[0],
		int _chi=0,int _math=0,int _eng=0) :chi(_chi),math(_math),eng(_eng){
		updateSum();
		if(ids.find(_id)!=ids.end()){
			throw "账号重复，请检查输入";
			return;
		}
		ids.insert(id);
		name=_name;id=_id;
		pass=_pass;
		if(_gender==g[0]||_gender==g[1])
			gender=_gender;
		else
			throw "性别错误(只能输入男/女)";
	}
	void work(){
		cout<<"********************"<<endl;
		cout<<"*|----------------|*"<<endl;
		cout<<"*|  学生查分系统  |*"<<endl;
		cout<<"*|----------------|*"<<endl;
		cout<<"*| 1.退出账号     |*"<<endl;
		cout<<"*| 2.修改密码     |*"<<endl;
		cout<<"*| 3.显示我的信息 |*"<<endl;
		cout<<"*|----------------|*"<<endl;
		cout<<"********************"<<endl;
		while(1){
			cout<<"请选择操作: ";
			int choice;
			cin>>choice;
			string s;
			switch(choice){
			case 1:
				login();
				return;
			case 2:
				cout<<"新密码: ";
				cin>>s;
				changePass(s);
				save();
				break;
			case 3:
				show();
				break;
			default:
				cout<<"没有此操作，请重试"<<endl;
			}
		}
	}
	void show(){
		cout<<"学号: "<<id<<"\t密码: "<<pass<<"\t姓名: "<<name<<"\t性别: "<<gender
			<<"\t语文: "<<chi<<"\t数学: "<<math<<"\t英语: "<<eng<<"\t总分: "<<sum<<endl;
	}
	friend class teacher;
	friend ostream& operator<<(ostream& out,student& p);
	friend istream& operator>>(istream& in,student& p);
};
ostream& operator<<(ostream& out,student& p){
	out<<p.id<<'\t'<<p.pass<<'\t'<<p.name<<'\t'<<p.gender<<'\t'
		<<p.chi<<'\t'<<p.math<<'\t'<<p.eng<<'\t'<<p.sum;
	return out;
}
istream& operator>>(istream& in,student& p){
	in>>p.id>>p.pass>>p.name>>p.gender>>p.chi>>p.math>>p.eng>>p.sum;
	return in;
}
vector<student> students;
void addStudent(){
	cout<<"学号 姓名 性别:"<<endl;
	string a,b,c;
	cin>>a>>b>>c;
	cout<<"语文 数学 英语分数:"<<endl;
	int e,f,g;
	cin>>e>>f>>g;
	students.push_back(student(a,"8888",b,c,e,f,g));
}
class teacher :public person{
private:
	vector<student>::iterator findStu(){
		cout<<"要搜索学号还是姓名？（0:学号 其他:姓名）";
		int op;
		cin>>op;
		cout<<"要搜索的内容: ";
		string s;
		cin>>s;
		auto iter=students.begin();
		for(;iter<=students.end();iter++){
			string ss=op?iter->name:iter->id;
			if(ss==s){
				break;
			}
		}
		return iter;
	}
	void barGraph(){
		int n=students.size();
		int*a=new int[n],i=0;
		for(student s:students)
			a[i++]=s.sum;
		sort(a,a+n);
		float l=a[0],r=a[n-1],dl=(r-l)/10;
		int per[10],x=0;
		for(int i=0;i<10;i++){
			cout<<setiosflags(ios::fixed)<<setprecision(1)<<l<<endl;
			cout<<'\t';
			int c=0;
			l+=dl;
			for(;a[x]<=l+0.001&&x<n;x++)
				c++;
			c=c*50/n;
			while(c--)cout<<'*';
			cout<<endl;
		}
		cout<<r<<endl;
		delete[] a;
	}
public:
	void set(string _id="",string _pass="8888"){
		id=_id;
		pass=_pass;
		ids.insert(id);
	}
	void work(){
		cout<<"********************"<<endl;
		cout<<"*|----------------|*"<<endl;
		cout<<"*|  学生管理系统  |*"<<endl;
		cout<<"*|----------------|*"<<endl;
		cout<<"*| 1.退出账号     |*"<<endl;
		cout<<"*| 2.修改密码     |*"<<endl;
		cout<<"*| 3.增加学生信息 |*"<<endl;
		cout<<"*| 4.删除学生信息 |*"<<endl;
		cout<<"*| 5.修改学生信息 |*"<<endl;
		cout<<"*| 6.查找学生信息 |*"<<endl;
		cout<<"*| 7.显示分数分布 |*"<<endl;
		cout<<"*| 8.关闭系统     |*"<<endl;
		cout<<"*|----------------|*"<<endl;
		cout<<"********************"<<endl;
		while(1){
			cout<<"请选择操作: ";
			int choice;
			cin>>choice;
			string s;
			vector<student>::iterator iter;
			switch(choice){
			case 1:
				login();
				return;
			case 2:
				cout<<"新密码: ";
				cin>>s;
				changePass(s);
				break;
			case 3:
				addStudent();
				save();
				break;
			case 4:
				iter=findStu();
				if(iter==students.end())
					cout<<"没有此人"<<endl;
				else
					students.erase(iter);
				save();
				break;
			case 5:
				iter=findStu();
				if(iter==students.end())
					cout<<"没有此人"<<endl;
				else{
					iter->show();
					cout<<"********************"<<endl;
					cout<<"*|----------------|*"<<endl;
					cout<<"*|  修改哪项? |*"<<endl;
					cout<<"*|----------------|*"<<endl;
					cout<<"*| 1.学号     |*"<<endl;
					cout<<"*| 2.密码重置 |*"<<endl;
					cout<<"*| 3.性别     |*"<<endl;
					cout<<"*| 4.语文分数 |*"<<endl;
					cout<<"*| 5.数学分数 |*"<<endl;
					cout<<"*| 6.英语分数 |*"<<endl;
					cout<<"*|----------------|*"<<endl;
					cout<<"********************"<<endl;
					student& stu=students[iter-students.begin()];
					int choice;
					cin>>choice;
					string s;
					int n;
					switch(choice){
					case 1:
						cin>>s;
						stu.id=s;
						break;
					case 2:
						stu.pass="8888";
						break;
					case 3:
						cin>>s;
						while(s!=g[0]&&s!=g[1]){
							cout<<"性别错误(只能输入男/女)"<<endl;
							cin>>s;
						}
						stu.gender=s;
						break;
					case 4:
						cin>>n;
						stu.chi=n;
						break;
					case 5:
						cin>>n;
						stu.math=n;
						break;
					case 6:
						cin>>n;
						stu.eng=n;
						break;
					}
					stu.updateSum();
					save();
				}
				break;
			case 6:
				iter=findStu();
				if(iter==students.end())
					cout<<"没有此人"<<endl;
				else
					iter->show();
				break;
			case 7:
				barGraph();
				break;
			case 8:
				save();
				cout<<"系统关闭" << endl;
				exit(0);
			default:
				cout<<"没有此操作，请重试"<<endl;
			}
		}
	}
	friend ostream& operator<<(ostream& out,teacher& p);
	friend istream& operator>>(istream& in,teacher& p);
};
ostream& operator<<(ostream& out,teacher& p){
	out<<p.id<<'\t'<<p.pass;
	return out;
}
istream& operator>>(istream& in,teacher& p){
	in>>p.id>>p.pass;
	return in;
}
teacher admin;
string filepath="data.txt";
void save(){
	fstream file(filepath,ios::out);
	if(!file.is_open()){
		cout<<"error"<<endl;
	}
	file<<admin<<endl;
	for(auto s:students){
		file<<s<<endl;
	}
	file.close();
	cout<<"文件已保存"<<endl;
}
void load(){
	fstream file(filepath,ios::in);
	if(!file.is_open()){
		cout<<"error"<<endl;
	}
	file>>admin;
	students.clear();
	student s;
	while(file>>s){
		students.push_back(s);
	}
	file.close();
	cout<<"文件已读取"<<endl;
}
bool isFileExists(){
	ifstream f(filepath);
	return f.good();
}
void init(){
	ids.clear();
	cout<<"没有数据，需要初始化"<<endl;
	string id,pass;
	cout<<"管理员账号: ";
	cin>>id;
	cout<<"管理员密码: ";
	cin>>pass;
	admin.set(id,pass);

	students.clear();
	int num;
	cout<<"人数"<< endl;
	cin>>num;
	while(num--){
		try{
			addStudent();
		}
		catch(const char* msg){
			cout<<msg<<endl;
			num++;
		}
	}
	save();
}
void login(){
	string id,pass;
	cout<<"账号: ";
	cin>>id;
	cout<<"密码(默认为8888): ";
	cin>>pass;
	if(admin.loginCheck(id,pass))
		return;
	for(student& a : students)
		if(a.loginCheck(id,pass))
			return;
	cout<<"账号密码有误，请重试"<<endl;
	login();
}
int main(){
	if(isFileExists())
		load();
	else
		init();
	login();
}