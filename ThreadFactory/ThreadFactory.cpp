
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

// ---------- глобальні змінні --- //
vector<int> storage;
mutex mtx;
condition_variable cv;
bool done = false;


void producer();
void consumer();

void producer() {
	for (int i = 1; i <= 20; i++) {
		{
			lock_guard<mutex> lock(mtx);
			storage.push_back(i);
			cout << "Додано на склад: " << i << endl;
		}
		cv.notify_all();
	}
	//--завершення--//
	done = true;
	cv.notify_all();
}


void consumer() {
	while (true)
	{
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, []()
			{
				return !storage.empty() || done;
			}
		);
		if (storage.empty() && done)
			break;

		int value = storage.back();
		storage.pop_back();
		cout << "Забрано зі складу: " << value << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "uk_UA.UTF-8");
	cout << "Моделювання роботи заводу розпочато..." << endl;
	cout << "Producer started" << endl;
	cout << "Consumer started" << endl;

	// ---- запуск потоків виробника і споживача ----- //
	thread producerThread(producer);
	thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();

	cout << "Роботу завершено. Усі 20 елементів оброблено." << endl;
	return 0;



}

