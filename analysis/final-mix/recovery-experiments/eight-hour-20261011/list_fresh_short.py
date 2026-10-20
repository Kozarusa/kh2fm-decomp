import sqlite3
import json
from pathlib import Path
base = Path(__file__).resolve().parent
db_path = base.parents[1] / 'worker-coordination/recovery-queue.sqlite3'
db = sqlite3.connect(db_path.as_uri() + '?mode=ro', uri=True)
rows = db.execute('select address,metadata from targets where state=? and queue=? and attempts=0', ('ready', 'general')).fetchall()
for address, text in rows:
    row = json.loads(text)
    if row['bytes'] <= 56:
        print(address, row['bytes'], row.get('best_proposal'))
