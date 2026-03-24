# Abstraction

class EmailServer:

    def _connect(self):
        print("Connecting to server...")

    def _authenticate(self):
        print("Authenticating...")

    def _disconnect(self):
        print("Disconnecting from server...")

    def send_email(self):
        self._connect()
        self._authenticate()
        print("Sending email...")
        self._disconnect()


email1 = EmailServer()
email1.send_email()
