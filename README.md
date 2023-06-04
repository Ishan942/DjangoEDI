# Smart Polyhouse with Remote Monitoring and Crop Prediction

This project implements a smart polyhouse system that utilizes various sensors to monitor the conditions inside the polyhouse. The collected data is uploaded to the cloud, where it is used for remote monitoring and control. Additionally, the data is used to train a machine learning model for crop prediction.

## Features

- Remote monitoring of polyhouse conditions
- Real-time data collection from various sensors
- Data upload to the cloud for storage and analysis
- Machine learning model for crop prediction
- Control of polyhouse environment remotely using DC motors

## Technologies Used

- NODE MCU for sensor data collection and control
- Django web framework for the user interface
- Cloud platform for data storage and analysis
- Machine learning libraries for crop prediction
- Arduino IDE for NODE MCU's coding

## Setup and Installation

1. Clone the repository:

2. Install the necessary dependencies:

3. Configure the NODE MCU to connect to the sensors and motors.

4. Update the Django settings file with the required configurations.

5. Run the Django development server:

7. Access the application by visiting `http://localhost:8000` in your web browser.

## Usage

- The web interface provides real-time monitoring of the polyhouse conditions.
- Sensor data is automatically uploaded to the cloud for further analysis.
- Use the machine learning model to predict crop yields based on historical data.
- Control the polyhouse environment remotely by sending commands to the NODE MCU, which controls the DC motors.





