db = '/home/pi/sensorreadings.json'
import schedule
import time
input_limit = 100000

def clear_db():
    inputs = 0
    with open(db, 'r') as outfile:
        for object in outfile:
            inputs +=1
    print(f"Number of database entries: {inputs}")
    if inputs >= input_limit:
        with open(db, 'w') as outfile:
            outfile.write("")
            print("db emptied")

schedule.every().day.at("23:00").do(clear_db)

if __name__ == '__main__':
    while True:
        schedule.run_pending()
        time.sleep(1)