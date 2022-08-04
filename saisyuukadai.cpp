// saisyuukadai.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
#include<random>
using namespace std;


vector<int> v1{ 1,0,1,0,0 }; //初期遺伝子型1
vector<int> v2{ 0,1,0,1,1 }; //初期遺伝子型2
vector<int> v3{ 1,1,0,0,1 }; //初期遺伝子型3
vector<int> v4{ 0,1,1,1,1 }; //初期遺伝子型4
vector<int> v5{ 1,0,1,0,1 }; //初期遺伝子型5
vector<int> v6{ 1,1,1,0,1}; //初期遺伝子型6
vector<int> v7{ 0,1,1,1,0 }; //初期遺伝子型7
vector<int> v8{ 1,1,0,1,0 }; //初期遺伝子型8

int W = 7; //ナップザックに入る重さの上限

struct jewelry {
	int weight; //詰める物の価値
	int value; //詰める物の重さ
}; //価値と重さの情報を持つ物体をクラスを用いて定義する
jewelry i1{4, 9}; //物体1
jewelry i2{ 1, 8 }; //物体2
jewelry i3{ 3, 7 }; //物体3
jewelry i4{ 2, 3 }; //物体4
jewelry i5{ 3, 6 }; //物体5

int sumvalue(vector<int> v) { 
	auto it = v.begin();
	int a = *it;
	int b = *(it + 1);
	int c = *(it + 2);
	int d = *(it + 3);
	int e = *(it + 4);
	return i1.value * a + i2.value * b + i3.value * c + i4.value * d + i5.value * e;
} //遺伝子型の価値合計を出力する関数

double fitness(vector<int>sv) {
	auto it2 = sv.begin();
	int a2 = *it2;
	int b2= *(it2 + 1);
	int c2 = *(it2+ 2);
	int d2 = *(it2 + 3);
	int e2 = *(it2 + 4);
	int sumweight = i1.weight * a2 + i2.weight * b2 + i3.weight * c2 + i4.weight * d2 + i5.weight * e2;
	if (sumweight <= W)return sumvalue(sv);
	else return sumvalue(sv) + 5 * (W - sumweight);
} //遺伝子型の適応度を出力する関数

double SelectionProbability(double f1 , double f2,double f3,double f4,double f5, double f6, double f7, double f8) {
	double denominator = f1 + f2 + f3 + f4 + f5 + f6 + f7 + f8;
	double x = f1 / denominator;
	return x;
} //その遺伝子型が選択される確率を出力する関数

vector<int> select(double fit1,double fit2,double fit3, double fit4, double fit5, double fit6,double fit7) {
	random_device engine;
	uniform_real_distribution<double> dist(0.0, 1.0);
	double  rand1 = dist(engine);
	double  rand2 = dist(engine);
	double  rand3 = dist(engine);
	double  rand4 = dist(engine);
	double  rand5 = dist(engine);
	double  rand6 = dist(engine);
	double  rand7 = dist(engine);
	double  rand8 = dist(engine);
	if (rand1 <= fit1) v1 = v1;
	if (fit1 < rand1 && rand1 <= fit1 + fit2) v1 = v2;
	if (fit1 + fit2 < rand1 && rand1 <= fit1 + fit2 + fit3) v1 = v3;
	if (fit1 + fit2 + fit3 < rand1 && rand1 <= fit1 + fit2 + fit3 + fit4) v1 = v4;
	if (fit1 + fit2 + fit3 + fit4 < rand1 && rand1 <= fit1 + fit2 + fit3 + fit4 + fit5) v1 = v5;
	if (fit1 + fit2 + fit3 + fit4 + fit5 < rand1 && rand1 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6)v1 = v6;
	if (fit1 + fit2 + fit3 + fit4 + fit5 + fit6 < rand1 && rand1 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6 + fit7)v1 = v7;
	else v1 = v8;

	if (rand2 <= fit1) v2 = v1;
	if (fit1 < rand2 && rand2 <= fit1 + fit2) v2 = v2;
	if (fit1 + fit2 < rand2 && rand2 <= fit1 + fit2 + fit3) v2 = v3;
	if (fit1 + fit2 + fit3 < rand2 && rand2 <= fit1 + fit2 + fit3 + fit4) v2 = v4;
	if (fit1 + fit2 + fit3 + fit4 < rand2 && rand2 <= fit1 + fit2 + fit3 + fit4 + fit5) v2 = v5;
	if (fit1 + fit2 + fit3 + fit4 + fit5 < rand2 && rand2 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6)v2 = v6;
	if (fit1 + fit2 + fit3 + fit4 + fit5 + fit6 < rand2 && rand2 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6 + fit7)v2 = v7;
	else v2 = v8;

	if (rand3 <= fit1) v3 = v1;
	if (fit1 < rand3 && rand3 <= fit1 + fit2) v3 = v2;
	if (fit1 + fit2 < rand3 && rand3 <= fit1 + fit2 + fit3) v3 = v3;
	if (fit1 + fit2 + fit3 < rand3 && rand3 <= fit1 + fit2 + fit3 + fit4) v3 = v4;
	if (fit1 + fit2 + fit3 + fit4 < rand3 && rand3 <= fit1 + fit2 + fit3 + fit4 + fit5) v3 = v5;
	if (fit1 + fit2 + fit3 + fit4 + fit5 < rand3 && rand3 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6)v3 = v6;
	if (fit1 + fit2 + fit3 + fit4 + fit5 + fit6 < rand3 && rand3 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6 + fit7)v3 = v7;
	else v3 = v8;

	if (rand4 <= fit1) v4 = v1;
	if (fit1 < rand4 && rand4 <= fit1 + fit2) v4 = v2;
	if (fit1 + fit2 < rand4 && rand4 <= fit1 + fit2 + fit3) v4 = v3;
	if (fit1 + fit2 + fit3 < rand4 && rand4 <= fit1 + fit2 + fit3 + fit4) v4 = v4;
	if (fit1 + fit2 + fit3 + fit4 < rand4 && rand4 <= fit1 + fit2 + fit3 + fit4 + fit5) v4 = v5;
	if (fit1 + fit2 + fit3 + fit4 + fit5 < rand4 && rand4 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6)v4 = v6;
	if (fit1 + fit2 + fit3 + fit4 + fit5 + fit6 < rand4 && rand4 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6 + fit7)v4 = v7;
	else v4 = v8;

	if (rand5 <= fit1) v5 = v1;
	if (fit1 < rand5 && rand5 <= fit1 + fit2) v5 = v2;
	if (fit1 + fit2 < rand5 && rand5 <= fit1 + fit2 + fit3) v5 = v3;
	if (fit1 + fit2 + fit3 < rand5 && rand5 <= fit1 + fit2 + fit3 + fit4) v5 = v4;
	if (fit1 + fit2 + fit3 + fit4 < rand5 && rand5 <= fit1 + fit2 + fit3 + fit4 + fit5) v5 = v5;
	if (fit1 + fit2 + fit3 + fit4 + fit5 < rand5 && rand5 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6)v5 = v6;
	if (fit1 + fit2 + fit3 + fit4 + fit5 + fit6 < rand5 && rand5 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6 + fit7)v5 = v7;
	else v5 = v8;

	if (rand6 <= fit1) v6 = v1;
	if (fit1 < rand6 && rand6 <= fit1 + fit2) v6 = v2;
	if (fit1 + fit2 < rand6 && rand6 <= fit1 + fit2 + fit3) v6 = v3;
	if (fit1 + fit2 + fit3 < rand6 && rand6 <= fit1 + fit2 + fit3 + fit4) v6 = v4;
	if (fit1 + fit2 + fit3 + fit4 < rand6 && rand6 <= fit1 + fit2 + fit3 + fit4 + fit5) v6 = v5;
	if (fit1 + fit2 + fit3 + fit4 + fit5 < rand6 && rand6 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6)v6 = v6;
	if (fit1 + fit2 + fit3 + fit4 + fit5 + fit6 < rand6 && rand6 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6 + fit7)v6 = v7;
	else v6 = v8;

	if (rand1 <= fit1) v7 = v1;
	if (fit1 < rand7 && rand7 <= fit1 + fit2) v7 = v2;
	if (fit1 + fit2 < rand7 && rand7 <= fit1 + fit2 + fit3) v7 = v3;
	if (fit1 + fit2 + fit3 < rand7 && rand7 <= fit1 + fit2 + fit3 + fit4) v7 = v4;
	if (fit1 + fit2 + fit3 + fit4 < rand7 && rand7 <= fit1 + fit2 + fit3 + fit4 + fit5) v7 = v5;
	if (fit1 + fit2 + fit3 + fit4 + fit5 < rand7 && rand7 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6)v7 = v6;
	if (fit1 + fit2 + fit3 + fit4 + fit5 + fit6 < rand7 && rand7 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6 + fit7)v7 = v7;
	else v7 = v8;

	if (rand8 <= fit1) v8 = v1;
	if (fit1 < rand8 && rand8 <= fit1 + fit2) v8 = v2;
	if (fit1 + fit2 < rand8 && rand8 <= fit1 + fit2 + fit3) v8 = v3;
	if (fit1 + fit2 + fit3 < rand8 && rand8 <= fit1 + fit2 + fit3 + fit4) v8 = v4;
	if (fit1 + fit2 + fit3 + fit4 < rand8 && rand8 <= fit1 + fit2 + fit3 + fit4 + fit5) v8 = v5;
	if (fit1 + fit2 + fit3 + fit4 + fit5 < rand8 && rand8 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6)v8 = v6;
	if (fit1 + fit2 + fit3 + fit4 + fit5 + fit6 < rand8 && rand8 <= fit1 + fit2 + fit3 + fit4 + fit5 + fit6 + fit7)v8 = v7;
	else v8 = v8;

	return v1, v2, v3, v4, v5, v6, v7, v8;
} //選択確率に基づいて次世代の遺伝子型を選択する関数



vector<int> crossoverv1(vector<int> v1, vector<int> v2, int rand1) {
	auto it1 = v1.begin();
	auto it2 = v2.begin();

	vector<int> crossv1;

	if (rand1 <= 0.2) {
		crossv1.push_back(*it1);
		crossv1.push_back(*(it1 + 1));
		crossv1.push_back(*(it2 + 2));
		crossv1.push_back(*(it2 + 3));
		crossv1.push_back(*(it2 + 4));
	}
	else crossv1 = v1;

	return crossv1;
} //交叉後の遺伝子型1を出力する関数

vector<int> crossoverv2(vector<int> v1, vector<int> v2, int rand1) {
	auto it1 = v1.begin();
	auto it2 = v2.begin();

	vector<int> crossv2;

	if (rand1 <= 0.5) {
		crossv2.push_back(*it2);
		crossv2.push_back(*(it2 + 1));
		crossv2.push_back(*(it1 + 2));
		crossv2.push_back(*(it1 + 3));
		crossv2.push_back(*(it1 + 4));
	}
	else crossv2 = v2;

	return crossv2;
} //交叉後の遺伝子型2を出力する関数

vector<int> crossoverv3(vector<int> v3, vector<int> v4, int rand2) {
	auto it3 = v3.begin();
	auto it4 = v4.begin();

	vector<int> crossv3;

	if (rand2 <= 0.5) {
		crossv3.push_back(*it3);
		crossv3.push_back(*(it3 + 1));
		crossv3.push_back(*(it4 + 2));
		crossv3.push_back(*(it4 + 3));
		crossv3.push_back(*(it4 + 4));
	}
	else crossv3 = v3;

	return crossv3;
} //交叉後の遺伝子型3を出力する関数

vector<int> crossoverv4(vector<int> v3, vector<int> v4, int rand2) {
	auto it3 = v3.begin();
	auto it4 = v4.begin();

	vector<int> crossv4;

	if (rand2 <= 0.5) {
		crossv4.push_back(*it4);
		crossv4.push_back(*(it4 + 1));
		crossv4.push_back(*(it3 + 2));
		crossv4.push_back(*(it3 + 3));
		crossv4.push_back(*(it3 + 4));
	}
	else crossv4 = v4;

	return crossv4;
} //交叉後の遺伝子型4を出力する関数

vector<int> crossoverv5(vector<int> v5, vector<int> v6, int rand3) {
	auto it5= v5.begin();
	auto it6 = v6.begin();

	vector<int> crossv5;

	if (rand3<= 0.5) {
		crossv5.push_back(*it5);
		crossv5.push_back(*(it5 + 1));
		crossv5.push_back(*(it6 + 2));
		crossv5.push_back(*(it6 + 3));
		crossv5.push_back(*(it6 + 4));
	}
	else crossv5 = v5;

	return crossv5;
} //交叉後の遺伝子型5を出力する関数

vector<int> crossoverv6(vector<int> v5, vector<int> v6, int rand3) {
	auto it5 = v5.begin();
	auto it6 = v6.begin();

	vector<int> crossv6;

	if (rand3 <= 0.5) {
		crossv6.push_back(*it6);
		crossv6.push_back(*(it6 + 1));
		crossv6.push_back(*(it5 + 2));
		crossv6.push_back(*(it5 + 3));
		crossv6.push_back(*(it5 + 4));
	}
	else crossv6 = v6;

	return crossv6;
}//交叉後の遺伝子型6を出力する関数

vector<int> crossoverv7(vector<int> v7, vector<int> v8, int rand4) {
	auto it7 = v7.begin();
	auto it8 = v8.begin();

	vector<int> crossv7;

	if (rand4 <= 0.5) {
		crossv7.push_back(*it7);
		crossv7.push_back(*(it7 + 1));
		crossv7.push_back(*(it8 + 2));
		crossv7.push_back(*(it8 + 3));
		crossv7.push_back(*(it8 + 4));
	}
	else crossv7 = v1;

	return crossv7;
} //交叉後の遺伝子型7を出力する関数

vector<int> crossoverv8(vector<int> v7, vector<int> v8, int rand4) {
	auto it7 = v7.begin();
	auto it8 = v8.begin();

	vector<int> crossv8;

	if (rand4 <= 0.5) {
		crossv8.push_back(*it8);
		crossv8.push_back(*(it8 + 1));
		crossv8.push_back(*(it7 + 2));
		crossv8.push_back(*(it7 + 3));
		crossv8.push_back(*(it7 + 4));
	}
	else crossv8 = v1;

	return crossv8;
}//交叉後の遺伝子型8を出力する関数



vector<int> mutation(vector<int> v) {
	auto it = v.begin();
	vector<int> mutv;
	random_device engine;
	uniform_real_distribution<double> dist(0.0, 1.0);
	double  rand1 = dist(engine);
	double  rand2 = dist(engine);
	double  rand3 = dist(engine);
	double  rand4 = dist(engine);
	double  rand5 = dist(engine);

	if (rand1 <= 0.3) {
		if (*it == 0)mutv.push_back(1);
		else mutv.push_back(0);
	}
	else mutv.push_back(*it);

	if (rand2 <= 0.3) {
		if (*it == 0)mutv.push_back(1);
		else mutv.push_back(0);
	}
	else mutv.push_back(*(it+1));

	if (rand3 <= 0.3) {
		if (*it == 0)mutv.push_back(1);
		else mutv.push_back(0);
	}
	else mutv.push_back(*(it+2));

	if (rand4 <= 0.3) {
		if (*it == 0)mutv.push_back(1);
		else mutv.push_back(0);
	}
	else mutv.push_back(*(it+3));

	if (rand5 <= 0.3) {
		if (*it == 0)mutv.push_back(1);
		else mutv.push_back(0);
	}
	else mutv.push_back(*(it+4));

	return mutv;
} //遺伝子型を入力すると，突然変異後の遺伝子型を出力する関数

int main()
{
	for (int i = 0; i < 10000; ++i) {

		int sumv1 = sumvalue(v1); //遺伝子型1の価値合計
		int sumv2 = sumvalue(v2); //遺伝子型2の価値合計
		int sumv3 = sumvalue(v3); //遺伝子型3の価値合計
		int sumv4 = sumvalue(v4); //遺伝子型4の価値合計
		int sumv5 = sumvalue(v5); //遺伝子型5の価値合計
		int sumv6 = sumvalue(v6); //遺伝子型6の価値合計
		int sumv7 = sumvalue(v7); //遺伝子型7の価値合計
		int sumv8 = sumvalue(v8); //遺伝子型8の価値合計

		double f1 = fitness(v1); //遺伝子型1の適応度
		double f2 = fitness(v2); //遺伝子型2の適応度
		double f3 = fitness(v3); //遺伝子型3の適応度
		double f4 = fitness(v4); //遺伝子型4の適応度
		double f5 = fitness(v5); //遺伝子型5の適応度
		double f6 = fitness(v6); //遺伝子型6の適応度
		double f7 = fitness(v7); //遺伝子型7の適応度
		double f8 = fitness(v8); //遺伝子型8の適応度

		double sp1 = SelectionProbability(f1, f2, f3, f4, f5, f6, f7, f8); //遺伝子型1の選択確率
		double sp2 = SelectionProbability(f2, f3, f4, f5, f6, f7, f8, f1); //遺伝子型2の選択確率
		double sp3 = SelectionProbability(f3, f4, f5, f6, f7, f8, f1, f2); //遺伝子型3の選択確率
		double sp4 = SelectionProbability(f4, f5, f6, f7, f8, f1, f2, f3); //遺伝子型4の選択確率
		double sp5 = SelectionProbability(f5, f6, f7, f8, f1, f2, f3, f4); //遺伝子型5の選択確率
		double sp6 = SelectionProbability(f6, f7, f8, f1, f2, f3, f4, f5); //遺伝子型6の選択確率
		double sp7 = SelectionProbability(f7, f8, f1, f2, f3, f4, f5, f6); //遺伝子型7の選択確率
		double sp8 = SelectionProbability(f8, f1, f2, f3, f4, f5, f6, f7); //遺伝子型8の選択確率

		select(sp1, sp2, sp3,sp4,sp5,sp6,sp7); //次世代の選択

		random_device engine;
		uniform_real_distribution<double> dist(0.0, 1.0);
		double  rand1 = dist(engine); //遺伝子型1，2の交叉が起こるかを決める乱数
		double  rand2 = dist(engine); //遺伝子型3，4の交叉が起こるかを決める乱数
		double  rand3 = dist(engine); //遺伝子型5，6の交叉が起こるかを決める乱数
		double  rand4 = dist(engine); //遺伝子型7，8の交叉が起こるかを決める乱数

		vector<int> crsv1 = crossoverv1(v1, v2, rand1); //交叉後の遺伝子型1
		vector<int> crsv2 = crossoverv2(v1, v2, rand1); //交叉後の遺伝子型2
		vector<int> crsv3 = crossoverv3(v3, v4, rand2); //交叉後の遺伝子型3
		vector<int> crsv4 = crossoverv4(v3, v4, rand2); //交叉後の遺伝子型4
		vector<int> crsv5 = crossoverv5(v5, v6, rand3); //交叉後の遺伝子型5
		vector<int> crsv6 = crossoverv6(v5, v6, rand3); //交叉後の遺伝子型6
		vector<int> crsv7 = crossoverv7(v7, v8, rand4); //交叉後の遺伝子型7
		vector<int> crsv8 = crossoverv8(v7, v8, rand4); //交叉後の遺伝子型8

		vector<int> mutv1 = mutation(crsv1); //突然変異後の遺伝子型1
		vector<int> mutv2 = mutation(crsv2); //突然変異後の遺伝子型2
		vector<int> mutv3 = mutation(crsv3); //突然変異後の遺伝子型3
		vector<int> mutv4 = mutation(crsv4); //突然変異後の遺伝子型4
		vector<int> mutv5 = mutation(crsv5); //突然変異後の遺伝子型5
		vector<int> mutv6 = mutation(crsv6); //突然変異後の遺伝子型6
		vector<int> mutv7 = mutation(crsv7); //突然変異後の遺伝子型7
		vector<int> mutv8 = mutation(crsv8); //突然変異後の遺伝子型8

	}
	cout << "生存個体" << endl;
	cout << "v1=[";
	for (auto x : v1) cout << x;
	cout << "]";
	cout << ",価値合計" << sumvalue(v1) << endl;
	cout << "v2=[";
	for (auto x : v2) cout << x;
	cout << "]";
	cout << ",価値合計" << sumvalue(v2) << endl;
	cout << "v3=[";
	for (auto x : v3) cout << x;
	cout << "]";
	cout << ",価値合計" << sumvalue(v3) << endl;
	cout << "v4=[";
	for (auto x : v4) cout << x;
	cout << "]";
	cout << ",価値合計" << sumvalue(v4) << endl;
	cout << "v5=[";
	for (auto x : v5) cout << x;
	cout << "]";
	cout << ",価値合計" << sumvalue(v5) << endl;
	cout << "v6=[";
	for (auto x : v6) cout << x;
	cout << "]";
	cout << ",価値合計" << sumvalue(v6) << endl;
	cout << "v7=[";
	for (auto x : v7) cout << x;
	cout << "]";
	cout << ",価値合計" << sumvalue(v7) << endl;
	cout << "v8=[";
	for (auto x : v8) cout << x;
	cout << "]";
	cout << ",価値合計" << sumvalue(v8) << endl;



}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します


