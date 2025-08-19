/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.clinic_management_system;
import java.text.ParseException;
import java.util.*;
import java.util.Scanner;
import java.text.SimpleDateFormat;


/**
 * @author Naveed Amar Guriro
 * @Title Clinic Management System
 * @version 1.0 This is my OOP Project and It is designed to assist small and
 * mid-sized clinics with core administrative tasks, including managing patient
 * and doctor records, appointment scheduling, and maintaining visit histories
 */
public class Clinic_Management_System {
    private static Clinic clinic;
    private static Scanner scanner = new Scanner(System.in);
    private static int patientCounter = 1;
    private static int doctorCounter = 1;
    private static int appointmentCounter = 1;

    public static void main(String[] args) {
        clinic = new Clinic("City Health Clinic");
        runMenu();
    }

    private static void runMenu() {
        int choice;
        do {
            displayMenu();
            System.out.print("Enter your choice: ");
            choice = getUserChoice();

            switch (choice) {
                case 1:
                    addPatient();
                    break;
                case 2:
                    addDoctor();
                    break;
                case 3:
                    scheduleAppointment();
                    break;
                case 4:
                    clinic.listAllPatients();
                    break;
                case 5:
                    clinic.listAllDoctors();
                    break;
                case 6:
                    clinic.listAllAppointments();
                    break;
                case 0:
                    System.out.println("Exiting Clinic Management System. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
            System.out.println("\n");
        } while (choice != 0);

        scanner.close();
    }

    private static void displayMenu() {
        System.out.println("--- Clinic Management Menu ---");
        System.out.println("1. Add New Patient");
        System.out.println("2. Add New Doctor");
        System.out.println("3. Schedule Appointment");
        System.out.println("4. List All Patients");
        System.out.println("5. List All Doctors");
        System.out.println("6. List All Appointments");
        System.out.println("0. Exit");
        System.out.println("----------------------------");
    }

    private static int getUserChoice() {
        while (!scanner.hasNextInt()) {
            System.out.println("Invalid input. Please enter a number.");
            scanner.next();
            System.out.print("Enter your choice: ");
        }
        int choice = scanner.nextInt();
        scanner.nextLine();
        return choice;
    }

    private static void addPatient() {
        System.out.println("\n--- Add New Patient ---");
        String patientId = "P" + String.format("%03d", patientCounter++);
        System.out.print("Enter patient name: ");
        String name = scanner.nextLine();
        System.out.print("Enter patient phone number: ");
        String phoneNumber = scanner.nextLine();
        System.out.print("Enter patient address: ");
        String address = scanner.nextLine();

        Patient newPatient = new Patient(patientId, name, phoneNumber, address);
        clinic.addPatient(newPatient);
    }

    private static void addDoctor() {
        System.out.println("\n--- Add New Doctor ---");
        String doctorId = "D" + String.format("%03d", doctorCounter++);
        System.out.print("Enter doctor name: ");
        String name = scanner.nextLine();
        System.out.print("Enter doctor specialization: ");
        String specialization = scanner.nextLine();
        System.out.print("Enter doctor phone number: ");
        String phoneNumber = scanner.nextLine();

        Doctor newDoctor = new Doctor(doctorId, name, specialization, phoneNumber);
        clinic.addDoctor(newDoctor);
    }

    private static void scheduleAppointment() {
        System.out.println("\n--- Schedule New Appointment ---");
        String appointmentId = "A" + String.format("%03d", appointmentCounter++);

        clinic.listAllPatients();
        System.out.print("Enter Patient ID for appointment: ");
        String patientId = scanner.nextLine();

        clinic.listAllDoctors();
        System.out.print("Enter Doctor ID for appointment: ");
        String doctorId = scanner.nextLine();

        System.out.print("Enter appointment date and time (YYYY-MM-DD HH:MM): ");
        String dateTimeString = scanner.nextLine();

        Date appointmentDateTime = null;
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm");
        try {
            appointmentDateTime = sdf.parse(dateTimeString);
        } catch (ParseException e) {
            System.out.println("Invalid date/time format. Please use YYYY-MM-DD HH:MM. Appointment not scheduled.");
            return;
        }

        clinic.scheduleAppointment(appointmentId, patientId, doctorId, appointmentDateTime);
    }
}