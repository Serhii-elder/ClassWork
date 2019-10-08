//#include <iostream>
//#include "Group.h"
//#include "Student.h"
//#include <string>
//
//using namespace std;
//
//Group::Group(string newNameG ,string newSpecial, int newCount ) {
//
//	nameG = newNameG;
//	special = newSpecial;
//	count = newCount;
//
//
//
//	//CalAvgMark();
//}
//
//void Group::AddStudent() {
//	Fill();
//	Student * newArr = new Student[count + 1];
//
//	for (int i = 0; i < count; i++) {
//
//		newArr[i] = arr[i];
//
//	}
//	Student stu;
//	stu.Fill();
//	newArr[count] = stu;
//	//delete[]arr;
//	arr = newArr;
//	++count;
//}
//
//
////void Group::CalAvgMark() {
////
////	avgMark = count / markOll;
////
////
////}
////
////void Group::MarkOll() {
////
////
////
////
////	for (int i = 0; i < count; i++) {
////	
////		markOll = markOll + student.mark;
////
////
////	}
////}
//
//void Group::Show() {
//	system("cls");
//	cout << "\n\tEnter name group: " << nameG << endl;
//	//cout << "\n\tEnter avgMarkGroup: " << avgMark << endl;
//	cout << "\n\tEnter special: " << special << endl;
//	cout << "\n\tEnter count: " << count << endl;
//	
//
//}
//
//void Group::Fill() {
//
//	cout << "\n\tEnter name: "; cin >> nameG;
//	
//	cout << "\n\tEnter special: "; cin >> special;
//	
//	cout << "\n\tEnter count: "; cin >> count;
//
//}