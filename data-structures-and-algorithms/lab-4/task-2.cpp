//
// Created by Naveed on 25/09/2025.
//

#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void linear_search(int employee_ids[], int id, int size)
{
    int time_complex = 0;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < size; i++)
    {
        time_complex++;
        if (id == employee_ids[i])
        {
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);

            cout << "ID found at " << employee_ids[i];
            cout << "\nNumber of operations taken with this " << id << " id is " << time_complex;
            cout << "\nTime taken: " << duration.count() << " nanoseconds";
            return;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "ID not found, even after " << time_complex << " operations.";
    cout << "\nTime taken: " << duration.count() << " nanoseconds";
}

void binary_search(int employee_ids[], int id, int size)
{
    int time_complex = 0;
    int first = 0;
    int last = size - 1;
    int mid = 0;

    auto start = high_resolution_clock::now();

    while (first <= last)
    {
        time_complex++;
        mid = (first + last) / 2;
        if (employee_ids[mid] == id)
        {
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);

            cout << "\nID found at " << employee_ids[mid];
            cout << "\nNumber of operations taken with this " << id << " id is " << time_complex;
            cout << "\nTime taken: " << duration.count() << " nanoseconds";
            return;
        }
        else if (employee_ids[mid] < id)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "ID not found, even after " << time_complex << " operations.";
    cout << "\nTime taken: " << duration.count() << " nanoseconds";
}

int main()
{
    int employee_ids[100] = {
        1231, 1232, 1233, 1234, 1235, 1236,
        1237, 1238, 1239, 1240, 1241, 1242,
        1243, 1244, 1245, 1246, 1247, 1248,
        1249, 1250, 1251, 1252, 1253, 1254,
        1255, 1256, 1257, 1258, 1259, 1260,
        1261, 1262, 1263, 1264, 1265, 1266,
        1267, 1268, 1269, 1270, 1271, 1272,
        1273, 1274, 1275, 1276, 1277, 1278,
        1279, 1280, 1281, 1282, 1283, 1284,
        1285, 1286, 1287, 1288, 1289, 1290,
        1291, 1292, 1293, 1294, 1295, 1296,
        1297, 1298, 1299, 1300, 1301, 1302,
        1303, 1304, 1305, 1306, 1307, 1308,
        1309, 1310, 1311, 1312, 1313, 1314,
        1315, 1316, 1317, 1318, 1319, 1320,
        1321, 1322, 1323, 1324, 1325, 1326,
        1327, 1328, 1329, 1330,
    };

    cout << "--Linear Search--" << endl;
    linear_search(employee_ids, 1319, 100);

    cout << endl << endl;

    cout << "--Binary Search--" << endl;
    binary_search(employee_ids, 1319, 100);
}
