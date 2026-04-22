#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Check if executable exists
if [ ! -f "./cub3D" ]; then
    echo -e "${RED}Error: cub3D executable not found${NC}"
    echo "Please run 'make' first"
    exit 1
fi

# Check if maps directory exists
if [ ! -d "./maps" ]; then
    echo -e "${RED}Error: maps directory not found${NC}"
    exit 1
fi

# Counters
total=0
passed=0
failed=0

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}  Testing all maps in maps/ directory  ${NC}"
echo -e "${BLUE}========================================${NC}"
echo ""

# Find all .cub files in maps directory
for map in maps/*.cub; do
    if [ -f "$map" ]; then
        total=$((total + 1))
        map_name=$(basename "$map")
        
        echo -e "${YELLOW}Testing:${NC} $map_name"
        
        # Run cub3D with the map (timeout after 2 seconds for validation)
        timeout 2s ./cub3D "$map" > /dev/null 2>&1
        exit_code=$?
        
        # Check exit code
        # 0 = success (program started, likely waiting for window close)
        # 124 = timeout (program is running, which is good for valid maps)
        # 1 = error
        if [ $exit_code -eq 0 ] || [ $exit_code -eq 124 ]; then
            echo -e "  ${GREEN}✓ PASS${NC} (exit code: $exit_code)"
            passed=$((passed + 1))
        else
            echo -e "  ${RED}✗ FAIL${NC} (exit code: $exit_code)"
            # Show error message
            ./cub3D "$map" 2>&1 | head -3 | sed 's/^/    /'
            failed=$((failed + 1))
        fi
        echo ""
    fi
done

# Summary
echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}  Summary${NC}"
echo -e "${BLUE}========================================${NC}"
echo -e "Total maps tested: $total"
echo -e "${GREEN}Passed: $passed${NC}"
echo -e "${RED}Failed: $failed${NC}"
echo ""

if [ $failed -eq 0 ]; then
    echo -e "${GREEN}All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed${NC}"
    exit 1
fi
