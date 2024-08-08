Features
----------------
Add Appointment: Insert a new appointment with a patient's name and urgency level.

Remove Appointment: Remove the most urgent appointment from the schedule.

Display Appointments: List all scheduled appointments sorted by urgency.

How It Works
----------------------
The MinHeap class maintains a priority queue of Appointment objects. 

Each Appointment has a patientName and an urgency level (with 1 being the most urgent).

The heap operations (heapifyUp and heapifyDown) ensure that the min-heap property is preserved, allowing efficient insertion and removal of appointments.

Classes
---------------
Appointment: Represents an appointment with a patient name and urgency level.

MinHeap: Implements the min-heap functionality for managing appointments.

Methods
------------
addAppointment(string name, int urgency): Adds a new appointment to the heap and maintains the heap property.

removeAppointment(): Removes the most urgent appointment from the heap and rebalances it.

displayAppointments(): Displays all appointments currently in the heap, sorted by urgency.

Usage
------------------
Compile and run the program to interact with the scheduler through a simple text-based menu.
The menu allows you to add, remove, and display appointments.
