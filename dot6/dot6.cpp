#include <iostream>
#include <vector>

#include <Eigen/Dense>
#include <chrono>


#include <opencv2/opencv.hpp>

using namespace std;
using namespace Eigen;

// Сортировка вектора
vector<int> sortVector(vector<int> v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] > v[j]) {
				swap(v[i], v[j]);
			}
		}
	}
	
	return v;
}

// Обратный порядок вектора
vector<int> reverseVector(vector<int> v) {
	vector<int> result;
	for (int i = v.size() - 1; i >= 0; --i) {
		result.push_back(v[i]);
	}

	return result;
}

// Сумма элементов вектора
int sum(vector<int> arr, int n) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	return sum;
}

// Частота числа x в векторе
int findFrequency(vector<int> arr, int x) {
	int count = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == x) {
			count++;
		}
	}

	return count;
}



int main()
{
	// ================================= ЗАДАНИЕ 1 =================================
	// Задание 1.1
	vector<int> v = { 5, 3, 6, 7, 1, 9 };
	vector<int> sorted = sortVector(v);

	for (int i = 0; i < sorted.size(); i++) {
		cout << sorted[i] << " ";
	}

	cout << endl;

	// Задание 1.2
	vector<int> reversed = reverseVector(v);

	for (int i = 0; i < reversed.size(); i++) {
		cout << reversed[i] << " ";
	}

	cout << endl;

	// Задание 1.3
	cout << "Sum: " << sum(v, v.size());

	cout << endl;

	// Задание 1.4
	cout << "Count: " << findFrequency(v, 9);

	cout << endl << "\n";
	// ============================== ЗАДАНИЕ 2 ================================
	// Матричное уравнение вида Ax=B
	Matrix2d A;
	Vector2d B;

	A << 2, 1,
		5, 7;

	B << 11, 13;

	auto start1 = chrono::high_resolution_clock::now();

	Vector2d X = A.colPivHouseholderQr().solve(B);

	auto end1 = chrono::high_resolution_clock::now();

	cout << "Solution Ax = B:\n";
	cout << X << endl;

	chrono::duration<double> time1 = end1 - start1;
	cout << "Time: " << time1.count() << " s\n\n";


	// Транспонированная матрица
	Matrix2d M;

	M << 1, 2,
		3, 4;

	auto start2 = chrono::high_resolution_clock::now();

	Matrix2d MT = M.transpose();

	auto end2 = chrono::high_resolution_clock::now();

	cout << "Transposed matrix:\n";
	cout << MT << endl;

	chrono::duration<double> time2 = end2 - start2;
	cout << "Time: " << time2.count() << " s\n";

	cout << endl << "\n";

	// ==================================== ЗАДАНИЕ 3 ===============================
	// Загружаем изображение
	cv::Mat image = cv::imread("C:/Users/константин/source/repos/dot6/x64/Debug/ho.jpg");
	if (image.empty()) {
		std::cerr << "Ошибка: не удалось загрузить изображение." << std::endl;
		return -1;
	}
	// Создаём окно для отображения
	cv::namedWindow("Исходное изображение", cv::WINDOW_NORMAL);
	cv::namedWindow("Обработанное изображение", cv::WINDOW_NORMAL);
	// Конвертируем в оттенки серого
	cv::Mat grayImage;
	cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
	// Применяем размытие по Гауссу
	cv::Mat blurredImage;
	cv::GaussianBlur(grayImage, blurredImage, cv::Size(5, 5), 0);
	// Отображаем результаты
	cv::imshow("Исходное изображение", image);
	cv::imshow("Обработанное изображение", blurredImage);
	// Ждём нажатия клавиши
	cv::waitKey(0);

}
