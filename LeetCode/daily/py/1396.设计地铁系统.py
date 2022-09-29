class UndergroundSystem:

    def __init__(self):
        self.tick_dict = {}
        self.time_dict = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.tick_dict[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        r = self.tick_dict[id][0]+stationName
        if self.time_dict.get(r):
            self.time_dict[r][0] += t - self.tick_dict[id][1]
            self.time_dict[r][1] += 1
        else:
            self.time_dict[r] = [t - self.tick_dict[id][1], 1]
        self.tick_dict.pop(id)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        elem = self.time_dict[startStation+endStation]

        return float(elem[0])/elem[1] if elem else None
