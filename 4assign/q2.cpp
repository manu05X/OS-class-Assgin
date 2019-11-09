#include <iostream>
#include <cstdio>

using namespace std;

bool existsInQueue(int *q, int pageId) {
	for (int i = 0; i < 3; i++) {
		if (q[i] == pageId)
			return true;
	}
	return false;
}

int main() {
	int pageRequests[20] = {0, 1, 20, 2, 20, 21, 32, 31, 0, 60, 0, 0, 16, 1, 17, 18, 32, 31, 0, 61};
	int queue[3] = {-1, -1, -1}, count = 0;

	for(int i = 0; i < 20; i++) {
		int pageId = pageRequests[i] >> 4;
		cout << "[Request]: " << pageId << endl;
		if (!existsInQueue(queue, pageId)) {
			count++;
			if (count > 3) {
				cout << "Page fault!" << endl;
				cout << "Frame " << queue[0] << " replaced with " << pageId << endl;
			}

			queue[0] = queue[1];
			queue[1] = queue[2];
			queue[2] = pageId;
		}
	}
	cout << "Total number of page faults: " << count << endl;
	return 0;
}
