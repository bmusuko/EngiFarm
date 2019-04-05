CXX      := -c++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := program
INCLUDE  := -Iinclude/
SRC      :=                      \
   $(wildcard src/Barn/*.cpp) \
   $(wildcard src/BeefRolade/*.cpp) \
   $(wildcard src/Buffalo/*.cpp) \
   $(wildcard src/BuffaloMeat/*.cpp)         \
   $(wildcard src/Cell/*.cpp) \
   $(wildcard src/Cheese/*.cpp) \
   $(wildcard src/Chicken/*.cpp) \
   $(wildcard src/ChickenEgg/*.cpp) \
   $(wildcard src/ChickenMeat/*.cpp) \
   $(wildcard src/Coop/*.cpp) \
   $(wildcard src/Cow/*.cpp) \
   $(wildcard src/CowMeat/*.cpp) \
   $(wildcard src/CowMilk/*.cpp) \
   $(wildcard src/Duck/*.cpp) \
   $(wildcard src/DuckEgg/*.cpp) \
   $(wildcard src/DuckMeat/*.cpp) \
   $(wildcard src/EggProducingFarmAnimal/*.cpp) \
   $(wildcard src/Facility/*.cpp) \
   $(wildcard src/FarmAnimal/*.cpp) \
   $(wildcard src/FarmProduct/*.cpp) \
   $(wildcard src/Game/*.cpp) \
   $(wildcard src/Goat/*.cpp) \
   $(wildcard src/GoatMeat/*.cpp) \
   $(wildcard src/GoatMilk/*.cpp) \
   $(wildcard src/Grassland/*.cpp) \
   $(wildcard src/Land/*.cpp) \
   $(wildcard src/LinkedList/*.hpp) \
   $(wildcard src/Martabak/*.cpp) \
   $(wildcard src/Matriks/*.cpp) \
   $(wildcard src/MeatProducingFarmAnimal/*.cpp) \
   $(wildcard src/MilkProducingFarmAnimal/*.cpp) \
   $(wildcard src/Mixer/*.cpp) \
   $(wildcard src/Player/*.cpp) \
   $(wildcard src/Product/*.cpp) \
   $(wildcard src/Sheep/*.cpp) \
   $(wildcard src/SheepMeat/*.cpp) \
   $(wildcard src/SideProduct/*.cpp) \
   $(wildcard src/Truck/*.cpp) \
   $(wildcard src/Well/*.cpp) \
   $(wildcard src/*.cpp)         \

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*
