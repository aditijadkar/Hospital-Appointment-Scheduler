#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Appointment {
public:
    string patientName;
    int urgency;

    Appointment(string name, int urg) : patientName(name), urgency(urg) {}
};

class MinHeap {
private:
    vector<Appointment> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)].urgency > heap[index].urgency) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int leftChild = left(index);
        int rightChild = right(index);

        if (leftChild < heap.size() && heap[leftChild].urgency < heap[smallest].urgency) {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild].urgency < heap[smallest].urgency) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    int parent(int index) {
        return (index - 1) / 2;
    }

    int left(int index) {
        return 2 * index + 1;
    }

    int right(int index) {
        return 2 * index + 2;
    }

public:
    void addAppointment(string name, int urgency) {
        Appointment newAppointment(name, urgency);
        heap.push_back(newAppointment);
        heapifyUp(heap.size() - 1);
    }

    void removeAppointment() {
        if (heap.empty()) {
            cout << "No appointments to remove.\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void displayAppointments() {
        if (heap.empty()) {
            cout << "No appointments scheduled.\n";
            return;
        }

        cout << "Appointments (sorted by urgency):\n";
        for (const auto &appointment : heap) {
            cout << "Patient Name: " << appointment.patientName << ", Urgency: " << appointment.urgency << "\n";
        }
    }
};

int main() {
    MinHeap scheduler;
    int choice;
    string name;
    int urgency;

    while (true) {
        cout << "\nHospital Appointment Scheduler\n";
        cout << "1. Add Appointment\n";
        cout << "2. Remove Appointment\n";
        cout << "3. Display Appointments\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient's name: ";
                cin >> name;
                cout << "Enter urgency (1-10, with 1 being most urgent): ";
                cin >> urgency;
                scheduler.addAppointment(name, urgency);
                break;
            case 2:
                scheduler.removeAppointment();
                break;
            case 3:
                scheduler.displayAppointments();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
