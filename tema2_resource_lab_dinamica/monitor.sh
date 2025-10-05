#!/usr/bin/env bash
# Simple monitor script for resource_lab
# Usage: ./monitor.sh <PID>

set -euo pipefail

if [ "${1:-}" = "" ]; then
  echo "Usage: $0 <PID>"
  exit 1
fi

PID="$1"

echo "[*] Monitoring PID $PID (press Ctrl+C to stop)"
echo
echo "Tip: in another terminal interact with ./resource_lab (alloc/free/cpu_start/cpu_stop)"

while true; do
  date
  ps -p "$PID" -o pid,vsz,rss,%mem,pcpu,cmd | tail -n +2
  echo "pmap total:"
  pmap -x "$PID" | tail -n 1 || true
  echo "-----"
  sleep 1
done
