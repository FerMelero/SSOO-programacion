
# resource_lab

Programa de laboratorio para generar y reducir consumo de **memoria** y **CPU** y monitorizarlo con herramientas de Linux.

## Requisitos
- gcc, make
- (opcional) htop, pmap, sysstat (pidstat, mpstat), watch

## Compilación
```bash
make
```

## Ejecución
```bash
./resource_lab
# o
make run
```

### Comandos dentro del programa
```
alloc <GiB>   # reserva y toca memoria (ej: alloc 2)
free          # libera la memoria
cpu_start <n> # arranca n hilos ocupados (busy-loop)
cpu_stop      # detiene los hilos
status        # muestra PID y estado
quit          # salir
```

## Monitorización (en otra terminal)
```bash
# identificar el PID (si no lo ves en htop)
pidof resource_lab

# ps
ps -p <PID> -o pid,ppid,cmd,vsz,rss,%mem,pcpu

# pmap
pmap -x <PID> | tail -n 5

# htop/top
htop  # busca por nombre o PID

# seguimiento en tiempo real
watch -n 1 "ps -p <PID> -o pid,vsz,rss,%mem,pcpu,cmd"
pidstat 1 -p <PID>        # requiere sysstat
mpstat -P ALL 1           # CPU por core
```

> Consejo: ejecuta en VM o contenedor de laboratorio. No usar en producción.

## Notas técnicas
- Las cadenas del programa están en ASCII para evitar problemas con LaTeX/listings en PDFs.
- El incremento de RSS se fuerza escribiendo una vez por página (4 KiB).
- Si el sistema entra en OOM, el kernel puede matar procesos. Trabaja en entorno controlado.
