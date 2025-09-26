/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.clinic_management_system;
import java.util.*;

public class Clinic {
private String name;
    private List<Patient> patients;
    private List<Doctor> doctors;
    private List<Appointment> appointments;

    public Clinic(String name) {
        this.name = name;
        this.patients = new ArrayList<>();
        this.doctors = new ArrayList<>();
        this.appointments = new ArrayList<>();
        System.out.println(name + " Clinic Management System Initialized.");
    }

    public void addPatient(Patient patient) {
        patients.add(patient);
        System.out.println("Patient added: " + patient.getName());
    }

    public Patient findPatientById(String patientId) {
        for (Patient p : patients) {
            if (p.getPatientId().equals(patientId)) {
                return p;
            }
        }
        return null;
    }

    public void listAllPatients() {
        System.out.println("\n--- All Patients in " + name + " ---");
        if (patients.isEmpty()) {
            System.out.println("No patients registered.");
            return;
        }
        for (Patient p : patients) {
            System.out.println(p);
        }
    }

    public void addDoctor(Doctor doctor) {
        doctors.add(doctor);
        System.out.println("Doctor added: " + doctor.getName());
    }

    public Doctor findDoctorById(String doctorId) {
        for (Doctor d : doctors) {
            if (d.getDoctorId().equals(doctorId)) {
                return d;
            }
        }
        return null;
    }

    public void listAllDoctors() {
        System.out.println("\n--- All Doctors in " + name + " ---");
        if (doctors.isEmpty()) {
            System.out.println("No doctors registered.");
            return;
        }
        for (Doctor d : doctors) {
            System.out.println(d);
        }
    }

    public void scheduleAppointment(String apptId, String patientId, String doctorId, Date dateTime) {
        Patient patient = findPatientById(patientId);
        Doctor doctor = findDoctorById(doctorId);

        if (patient != null && doctor != null) {
            Appointment newAppointment = new Appointment(apptId, patient, doctor, dateTime);
            appointments.add(newAppointment);
            System.out.println("\nAppointment scheduled successfully:");
            System.out.println(newAppointment);
        } else {
            System.out.println("\nFailed to schedule appointment. Please ensure Patient ID and Doctor ID are valid.");
        }
    }

    public void listAllAppointments() {
        System.out.println("\n--- All Appointments in " + name + " ---");
        if (appointments.isEmpty()) {
            System.out.println("No appointments scheduled.");
            return;
        }
        for (Appointment a : appointments) {
            System.out.println(a);
            System.out.println("--------------------");
        }
    }

    public String getName() {
        return name;
    }
}
