# 🌐 Departmental Network Isolation and Routing
### Project Type: VLAN Segmentation & Inter-VLAN Routing

This project implements a secure departmental network utilizing **Cisco Packet Tracer**.  
The design features **VLAN-based segmentation** to separate HR and IT departments, **Router-on-a-Stick** for inter-VLAN routing, and Access Control Lists (ACLs) to enforce security policies.

> ⚠️ This project demonstrates both logical segmentation and basic security. The topology includes an optional ACL configuration to block IT access to the HR server.

## 📘 Topics Covered
- VLAN Creation and Assignment (VLAN 10 & 20)
- Inter-VLAN Routing (Router-on-a-Stick)
- IP Subnetting and CIDR (/24)
- Access Control Lists (Standard ACLs)
- Network Security & Traffic Filtering

## ⚙️ Tools Required
- **Cisco Packet Tracer** (version 8.2 or later)

## 📊 Network Configuration Details
Below are the subnet calculations and addressing schemes used in this topology:

| Department | VLAN ID | Network Address | Gateway | Key Devices |
| :--- | :--- | :--- | :--- | :--- |
| **HR Dept** | 10 | `192.168.10.0/24` | `.1` | PC1 (`.10`), Server (`.50`) |
| **IT Dept** | 20 | `192.168.20.0/24` | `.1` | PC1 (`.10`), PC2 (`.11`) |

## 🚀 How to Use the Project
1. Clone or download this repository.
2. Locate the `.pkt` file named `departmental-network-routing.pkt` (or similar).
3. Open **Cisco Packet Tracer** on your system.
4. Click **File → Open**, then select the project file.
5. **Test Connectivity (Ping):**
   * **HR to HR:** Ping from HR PC1 to HR Server (Should Success).
   * **HR to IT:** Ping from HR PC1 to IT PC1 (Should Success).
6. **Test Security (ACL):**
   * Ping from **IT PC1** to **HR Server** (`192.168.10.50`).
   * *Result:* The ping should fail (Destination Host Unreachable) if the ACL is active.

> 💡 If you are viewing this on GitHub, download the `.pkt` file before opening it in Packet Tracer.

## 🧠 Learning Goal
Gain hands-on experience in designing scalable networks by implementing Layer 2 segmentation, configuring Layer 3 routing between subnets, and applying security policies to restrict sensitive resource access.