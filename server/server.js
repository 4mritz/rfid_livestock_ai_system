const express = require('express');
const app = express();
const port = process.env.PORT || 3000;

app.use(express.json());

// POST endpoint to receive RFID scans
app.post('/newscan', (req, res) => {
  const { cardID } = req.body;
  if (!cardID) {
    return res.status(400).json({ error: 'No cardID provided' });
  }

  // Log the scan and return success
  console.log('RFID Tag Received:', cardID);

  // Validate and insert into DB or forward to other services

  return res.status(200).json({ ok: true, cardID });
});

app.get('/', (req, res) => res.send('RFID server running'));

app.listen(port, () => console.log(`Server running at http://localhost:${port}`));
