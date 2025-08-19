/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.clinic_management_system;

public class Patient {

    private String patientId;
    private String name;
    private String phoneNumber;
    private String address;

    public Patient(String patientId, String name, String phoneNumber, String address) {
        this.patientId = patientId;
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.address = address;
    }

    public String getPatientId() {
        return patientId;
    }

    public String getName() {
        return name;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public String getAddress() {
        return address;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    @Override
    public String toString() {
        return "Patient [ID: " + patientId + ", Name: " + name + ", Phone: " + phoneNumber + ", Address: " + address + "]";
    }
}
