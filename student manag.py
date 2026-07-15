students = []

while True:
    print("\n===== Student Management System =====")
    print("1. Add Student")
    print("2. View Students")
    print("3. Search Student")
    print("4. Update Student")
    print("5. Delete Student")
    print("6. Exit")

    choice = input("Enter your choice: ")

    # Add Student
    if choice == "1":
        roll = input("Enter Roll Number: ")
        name = input("Enter Name: ")
        age = input("Enter Age: ")
        course = input("Enter Course: ")

        student = {
            "Roll": roll,
            "Name": name,
            "Age": age,
            "Course": course
        }

        students.append(student)
        print("Student added successfully!")

    # View Students
    elif choice == "2":
        if len(students) == 0:
            print("No student records found.")
        else:
            print("\nStudent Records:")
            for s in students:
                print(f"Roll: {s['Roll']}, Name: {s['Name']}, Age: {s['Age']}, Course: {s['Course']}")

    # Search Student
    elif choice == "3":
        roll = input("Enter Roll Number to search: ")
        found = False

        for s in students:
            if s["Roll"] == roll:
                print("\nStudent Found:")
                print(f"Roll: {s['Roll']}")
                print(f"Name: {s['Name']}")
                print(f"Age: {s['Age']}")
                print(f"Course: {s['Course']}")
                found = True
                break

        if not found:
            print("Student not found!")

    # Update Student
    elif choice == "4":
        roll = input("Enter Roll Number to update: ")
        found = False

        for s in students:
            if s["Roll"] == roll:
                s["Name"] = input("Enter New Name: ")
                s["Age"] = input("Enter New Age: ")
                s["Course"] = input("Enter New Course: ")
                print("Student record updated successfully!")
                found = True
                break

        if not found:
            print("Student not found!")

    # Delete Student
    elif choice == "5":
        roll = input("Enter Roll Number to delete: ")
        found = False

        for s in students:
            if s["Roll"] == roll:
                students.remove(s)
                print("Student record deleted successfully!")
                found = True
                break

        if not found:
            print("Student not found!")

    # Exit
    elif choice == "6":
        print("Thank you for using Student Management System!")
        break

    else:
        print("Invalid choice! Please try again.")