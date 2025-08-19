/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab7;

/**
 *
 * @author navee
 */
public class Room {

    private int roomId, pricePerNight;
    private String roomType;
    private boolean availability;

    public Room(int roomId, int pricePerNight, String roomType, boolean availability) {
        this.roomId = roomId;
        this.pricePerNight = pricePerNight;
        this.roomType = roomType;
        this.availability = availability;
    }

    public Room() {
        this(1, 100, "Standard", true);
    }

    public int getroomId() {
        return roomId;
    }

    public void setroomId(int roomID) {
        this.roomId = roomID;
    }

    public int getPricePerNight() {
        return pricePerNight;
    }

    public void setPricePerNight(int pricePerNight) {
        this.pricePerNight = pricePerNight;
    }

    public String getRoomType() {
        return roomType;
    }

    public void setRoomType(String roomType) {
        this.roomType = roomType;
    }

    public boolean isAvailability() {
        return availability;
    }

    public void setAvailability(boolean availability) {
        this.availability = availability;
    }

    public double calculateBookingCost(int numberOfNights) {
        return (numberOfNights * pricePerNight);
    }
    
    public double calculateBookingCost(int numberOfNights, double discountPercentage){
        return ( (numberOfNights * pricePerNight) * discountPercentage );
    }
    

}
