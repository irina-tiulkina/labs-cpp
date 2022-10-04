// See https://aka.ms/new-console-template for more information
Console.WriteLine("Hello, World!");

string str = "str1";
MyClass myClass = new MyClass();
myClass.str = "MyClass1";
Console.WriteLine(str + " " + myClass.str);
FuncStr(str);
FuncObj(myClass);
Console.WriteLine(str + " " + myClass.str);

void FuncStr(string str)
{
    str = "str2";
}

void FuncObj(MyClass myClass)
{
    myClass.str = "MyClass2";
    myClass = new MyClass();
    myClass.str = "123";
}

class MyClass
{
    public string str = "";
}