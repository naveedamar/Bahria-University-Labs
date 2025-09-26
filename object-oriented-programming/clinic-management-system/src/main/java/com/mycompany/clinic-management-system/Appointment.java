/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.clinic-management-system;
import java.util.Date;
import java.util.Calendar;
import java.text.SimpleDateFormat;
/**
 *
 * @author navee
 */
public class Appointment {
    private String appointmentId;
    private Patient patient;
    private Doctor doctor;
    private Date appointmentDateTime;
    private String notes;

    private static final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("yyyy-MM-dd HH:mm");

    public Appointment(String appointmentId, Patient patient, Doctor doctor, Date appointmentDateTime) {
        this.appointmentId = appointmentId;
        this.patient = patient;
        this.doctor = doctor;
        this.appointmentDateTime = appointmentDateTime;
        this.notes = "No specific notes.";
    }

    public String getAppointmentId() {
        return appointmentId;
    }

    public Patient getPatient() {
        return patient;
    }

    public Doctor getDoctor() {
        return doctor;
    }

    public Date getAppointmentDateTime() {
        return appointmentDateTime;
    }

    public String getNotes() {
        return notes;
    }

    public void setNotes(String notes) {
        this.notes = notes;
    }

    @Override
    public String toString() {
        return "Appointment [ID: " + appointmentId + "]\n" +
               "  - Patient: " + patient.getName() + " (ID: " + patient.getPatientId() + ")\n" +
               "  - Doctor: " + doctor.getName() + " (Spec: " + doctor.getSpecialization() + ")\n" +
               "  - Time: " + DATE_FORMAT.format(appointmentDateTime) + "\n" +
               "  - Notes: " + notes;
    }
}
